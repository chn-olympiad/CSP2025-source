#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int use[205][205][205];
int n;
int dfs(int i,int na,int nb,int nc){
	int ans=-1;
	if(i>n){
		return 0;
	}
	if(use[na][nb][nc]==-1){
		
		if(2*na<n){
			ans=max(ans,a[i]+dfs(i+1,na+1,nb,nc));
		}
		if(2*nb<n){
			ans=max(ans,b[i]+dfs(i+1,na,nb+1,nc));
		}
		if(2*nc<n){
			ans=max(ans,c[i]+dfs(i+1,na,nb,nc+1));
		}
		use[na][nb][nc]=ans;
	}
//	cout<<na<<" "<<nb<<" "<<nc<<" "<<use[na][nb][nc]<<endl;
	return use[na][nb][nc];
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(use,-1,sizeof(use));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n>200){
			sort(a+1,a+n+1);
			long long ans=0;
			for(int i=n;i>n/2;i++){
				ans+=a[i];
			}
			cout<<ans;
			break;
		}
		cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
}
