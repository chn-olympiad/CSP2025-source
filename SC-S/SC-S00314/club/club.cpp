#include <bits/stdc++.h>
using namespace std;
int t,n,a[10010][5],d[10010][5],G[5],lll[5]={-1,-1,-1,-1,-1};
stack<int> last[5];
int find_next(int j,int g){
	int l=(g-2)%3+1,r=((g-1)%3+1);
	if(l<=0)l+=3;
	if(d[j][l]>0)return r;
	else if(-d[j][r]>0)return l;
	if(d[j][l]>-d[j][r])return l;
	else return r;
}
int find_next2(int j,int g){
	int l=(g-2)%3+1,r=((g-1)%3+1);
	if(l<=0)l+=3;
	if(d[j][l]>0)return r;
	else if(-d[j][r]>0)return l;
	if(d[j][l]>-d[j][r])return l;
	else return r%3+1;
}
int cp(int j1,int j2){
	int g1=a[j1][0],o1=find_next(j1,g1),l1;
	l1=d[j1][o1];
	int g2=a[j2][0],o2=find_next(j2,g2),l2;
	l2=d[j2][o2];
	if(l2-l1>=0){last[g1].push(j1);return j1;}
	else return j2;
}
void join(int j,int g){
	if(lll[g]!=j){
		if(lll[g]==-1)lll[g]=j;
		lll[g]=cp(j,lll[g]);
	}
	if(G[g]<n/2){G[g]++;a[j][0]=g;}
	else {
		a[lll[g]][0]=find_next2(lll[g],a[lll[g]][0]);
		last[g].pop();
		join(lll[g],a[lll[g]][0]);
		if(!last[g].empty()){
			lll[g]=last[g].top();
		}else return;
		if(j!=lll[g])a[j][0]=g;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=0;j<5;j++){
			stack<int> emp;
			lll[j]=-1;
			last[j].swap(emp);
			G[j]=0;
		}
		for(int j=1;j<=n;j++){
			int g=-1,mx=-1;
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
				if(a[j][k]>=mx)g=k,mx=a[j][k];
			}
			for(int k=1;k<=3;k++){
				d[j][k]=a[j][(k-1)%3+1]-a[j][k%3+1];
			}
			a[j][0]=g;
			join(j,g);
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			ans+=a[j][a[j][0]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}