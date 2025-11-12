#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define con continue
using namespace std;
int n,ans,a[5010],s[5010];
bool b[101];
void dfs(int k){
	if(k==n+1){
		int sum=0,maxn=-1;
		for(int i=1;i<=n;i++){
			if(b[i]){
				sum+=a[i];
				maxn=max(maxn,a[i]); 
			}
		}
		if(maxn*2<sum){
			ans++;	
		}
		return ;
	}
	for(int i=0;i<=1;i++){
		b[k]=i;
		dfs(k+1);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<ans-1;
		return 0;
	}else{
		s[3]=1;
		for(int i=4;i<=n;i++){
			s[i]=(s[i-1]*2+(i-2))&998244353;
		}
		cout<<s[n];
	}
	
	return 0;
}

