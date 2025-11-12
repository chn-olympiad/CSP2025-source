#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=0;
int a[5005],v[5005];
void dfs(int k,int s,int mx){
	if(k>=4){
		if(s>2*mx){
			cnt++;
		}
	}
	if(k==n+1){
		return ;
	}
	for(int i=k;i<=n;i++){
		if(v[i]!=1){
			v[i]=1;
			dfs(k+1,s+a[i],max(mx,a[i]));
			v[i]=0;
		} 
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dfs(1,0,0);
	cout << cnt;
}