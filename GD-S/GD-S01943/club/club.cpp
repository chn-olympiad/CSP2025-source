#include<bits/stdc++.h>
using namespace std;
int n,ans=-1,p[4];
struct da{
	int big,mid,x,y,sma;
}b[100006];
void dfs(int node,int sum){
	if(node==n){
		ans=max(ans,sum);
		return ;
	}
	if(p[b[node+1].x]<n/2){
		p[b[node+1].x]++;
		dfs(node+1,sum+b[node+1].big);
	}else if(p[b[node+1].y]<n/2){
		p[b[node+1].y]++;
		dfs(node+1,sum+b[node+1].mid);
	}
} 
bool cmp(da u,da k){
	if(u.big-u.mid!=k.big-k.mid){
		return u.big-u.mid>k.big-k.mid;
	}else if(u.big!=k.big){
		return u.big>k.big;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			p[1]=0;
			p[2]=0;
			p[3]=0;
			int a[4];
			cin>>a[1]>>a[2]>>a[3];
			b[i].big=max(a[1],max(a[2],a[3]));
			b[i].sma=min(a[1],min(a[2],a[3]));
			bool flag1=0,flag2=0;
			for(int j=1;j<=3;j++){
				if(b[i].big==a[j] && !flag1){
					b[i].x=j;
					flag1=1;
				}else if(b[i].sma==a[j] && !flag2){
					flag2=1;
				}else{
					b[i].y=j;
					b[i].mid=a[j];
				}
			}
		}
		sort(b+1,b+n+1,cmp);
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
} 
