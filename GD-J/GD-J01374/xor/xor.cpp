#include<bits/stdc++.h>
#define int long long
const int Mn=5e5+5;
using namespace std;
int a[Mn];int n,k;
int ans1=0,ans=-1;
int xr(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum^a[i];
	}
	return sum;
}
void dfs(int l,int r,int q){
	int p=xr(l,r);
	if(p==k)ans1++;
	if(l+q<=n&&r+q<=n)dfs(l+q,r+q,q);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dfs(i,j,abs(i-j)+1);
			ans=max(ans,ans1);
			ans1=0;
		}
		
	}
	cout<<ans;
	return 0;
}
