#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int arr[N],ans,f[N],n;
void dfs(int x,int sum){
	ans=max(ans,sum);
	if(sum+n-x<ans||x==n)return ;
	for(int i=x+1;i<=n;++i){
		if(f[i]!=0)
		dfs(f[i]+i-1,sum+1);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	for(int i=1;i<=n;++i){
		int num=arr[i];
		if(num==k){
			f[i]=1;
			continue;
		}
		for(int j=i+1;j<=n;++j){
			num=num^arr[j];
			if(num==k){
				f[i]=j-i+1;
				break;
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

