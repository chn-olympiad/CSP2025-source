#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200001][4],an,nu[4],c1,c2;
int vi[200001],b[200001],c[200001],fl;
int f[201][201][201];
struct A{
	int nu,to,id;
	bool operator<(const A&t)const{
		return nu<t.nu;
	}
};
priority_queue<A>q;
priority_queue<int>q1;
void cl(){
	while(!q.empty())q.pop();
	while(!q1.empty())q1.pop();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n,nu[1]=n,nu[2]=nu[3]=an=0;
		cl(),c1=c2=0,fl=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			fl&=(a[i][3]==0);
		}
		if(fl){
			for(int i=1;i<=n;i++){
				an+=a[i][1];
				q1.push(a[i][2]-a[i][1]);
			}
			for(int i=1;i<=n/2;i++)
				an+=q1.top(),q1.pop();
			cout<<an<<'\n';
		}else if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++){
					for(int k=0;k<=min(n/2,i-j);k++){
						if(i-j-k>n/2)continue;
						f[i][j][k]=0;
						if(j>0)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
						if(k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
						if(i-j-k>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
					}
				}
			}
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++)
					an=max(an,f[n][i][j]);
			cout<<an<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				an+=a[i][1],vi[i]=0;
				q.push({a[i][2]-a[i][1],2,i});
				q.push({a[i][3]-a[i][1],3,i});
			}
			while(1){
				if(q.empty())break;
				A x=q.top();q.pop();
				if(nu[1]<=n/2&&x.nu<0)break;
				if(vi[x.id])continue;
				an+=x.nu,nu[1]--;
				nu[x.to]++,vi[x.id]=1;
				if(x.to==2)b[++c1]=x.id;
				else c[++c2]=x.id;
			}
			cl();
			if(nu[2]>n/2){
				for(int i=1;i<=c1;i++){
					int tp=b[i];
					q.push({a[tp][3]-a[tp][2],2,3});
				}
				for(int i=1;i<=nu[2]-n/2;i++)
					an+=q.top().nu,q.pop();
			}
			if(nu[3]>n/2){
				for(int i=1;i<=c2;i++){
					int tp=c[i];
					q.push({a[tp][2]-a[tp][3],3,2});
				}
				for(int i=1;i<=nu[3]-n/2;i++)
					an+=q.top().nu,q.pop();
			}
			cout<<an<<'\n';
		}
	}
	return 0;
}