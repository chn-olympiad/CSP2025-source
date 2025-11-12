#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn],b[maxn],c[maxn],d[maxn];
int ans=-1;
bool q0=1,vis[maxn][3];
void dfs(int cur,int p,int q,int r,int sum){
	if(cur==n+1){
		ans=max(ans,sum);
		return;
	}
	if(p<n/2) dfs(cur+1,p+1,q,r,sum+a[cur]);
	if(q<n/2) dfs(cur+1,p,q+1,r,sum+b[cur]);
	if(r<n/2) dfs(cur+1,p,q,r+1,sum+c[cur]);	
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		q0=1;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			if((b[i]&&c[i])||(a[i]&&c[i])||(a[i]&&b[i])) q0=0;
			else if((b[i]||c[i])==0) d[i]=a[i];
			else if((a[i]||c[i])==0) d[i]=b[i];
			else if((b[i]||a[i])==0) d[i]=c[i];
		}
		if(q0){
			sort(d+1,d+n+1);
			ans=0;
			for(int i=n;i>n/2;--i) ans+=d[i];
			cout<<ans;
		}else{
			dfs(0,0,0,0,0);
			cout<<ans;
		}
		cout<<endl;
	}
    return 0;
}
