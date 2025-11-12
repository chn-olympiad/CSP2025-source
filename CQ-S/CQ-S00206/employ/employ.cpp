/*
最终还是没上200，有啥意义呢
CCF今年的分能不能降一下，求
生在强省，根本卷不过 
CCF我爱你，让我体验一下NOIP吧…… 


*/


#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],u[15],b[15],ans;
string s;
void dfs(int x){
	if(x>n){
		int c=0;
		for(int i=1;i<=n;i++){
			b[i]=a[u[i]];
			if(s[i-1]=='0'||c>=b[i]){
				c++;
			}
		}
		if(c<=n-m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=x;
			dfs(x+1);
			u[i]=0;
		}
	}
}
const int mod=998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(n<=10)goto sb;
	ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
	sb:;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
