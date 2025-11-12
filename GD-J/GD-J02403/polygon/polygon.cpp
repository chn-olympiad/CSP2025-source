#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,a[6000],ans;
bool res[6000];
void dfs(int c,int maxn,int alln){
	if(c==n+1){
		if(maxn*2<alln){
			ans++;
			ans%=998244353;
		}
		return;
	}
	res[c]=1;
	dfs(c+1,max(maxn,a[c]),alln+a[c]);
	res[c]=0;
	dfs(c+1,maxn,alln);
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
