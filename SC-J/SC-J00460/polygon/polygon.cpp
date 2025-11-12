#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
ll a[N],n,ans,c,d[N],cnt,fx[]={-1,0,+1,0},fy[]={0,-1,0,+1};
//void dfs(ll x,ll y){
//	for(ll i=1;i<=n;i++){
//		if(fx[i]==x&&fy[i]==y) return;
//		dfs(fx[a[i]]+1,fy[a[i]]);
//		dfs(fx[a[i]],fy[a[i]]+1);
//		dfs(fx[a[i]]-1,fy[a[i]]);
//		dfs(fx[a[i]],fy[a[i]]-1);
//	}
//} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
//	for(ll i=1;i<=n-1;i++){
//		for(ll j=i+1;j<=n;j++){
//			c+=a[j],cnt++;
//			if(c>a[i]&&)
//		}
//	}
	for(ll i=1;i<=n-1;i++){
		cnt++;
		for(ll j=i+1;j<=n;j++){
			c+=a[j];
			if(a[i]<c&&cnt>=2&&a[i]>=a[j]&&i<j){
//				cout<<a[i]<<" "<<c<<" "<<cnt<<"\n";
				ans++;	
			} 	
		}
	}
	cout<<ans;
	return 0;
} 