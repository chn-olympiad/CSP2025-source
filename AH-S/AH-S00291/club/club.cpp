#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][201];
long long ans=-1;
void dfs(int i,int a1,int a2,int a3,long long sum){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	if(a1<n>>1)dfs(i+1,a1+1,a2,a3,sum+a[0][i]);
	if(a2<n>>1)dfs(i+1,a1,a2+1,a3,sum+a[1][i]);
	if(a3<n>>1)dfs(i+1,a1,a2,a3+1,sum+a[2][i]);
	return;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>200){
			int b[100001],b2,c;
			for(int i=1;i<=n;i++){
				cin>>b[i]>>b2>>c;
			}
			sort(b+1,b+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n>>1;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		ans=-1;
	}
	return 0;
}
