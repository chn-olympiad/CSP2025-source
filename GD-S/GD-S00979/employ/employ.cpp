#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m,s[N],c[N],ans;long long p=998244353;long long fb[N];
bool f[N];
void dfs(int k,int l,int q){
	if(m-q-1>n-k)return;
	if(k>n){
		if(q>=m){
			ans++;ans%=p;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(f[i])continue;
		f[i]=1;
		if(l>=c[i]){
			dfs(k+1,l+1,q);
		}
		else{
			if(s[k]){
				dfs(k+1,l,q+1);
			}
			else{
				dfs(k+1,l+1,q);
			}
		}
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char ch;cin >> ch;s[i]=ch-'0';
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(n<=18){
		dfs(1,0,0);
		cout << ans;
	}
	else{
		if(m==n){
			fb[0]=1;
			for(int i = 1; i <= n; i++){
				fb[i]=fb[i-1]%p*(long long)(i)%p;
				if(s[i]==0||c[i]==0){
					cout << 0;return 0;
				}
			}
			cout << fb[n];return 0;
		}
	}
	return 0;
}

