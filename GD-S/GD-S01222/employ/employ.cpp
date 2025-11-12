#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans;
int n, m, num, luqu;
bool vis[505];
int a[505];
int people[505];
void f(int i){
	if(luqu>=m){
		if(n-i+1<=1) ans++;
		else{
			long long chen=1;
			for(int k=n-i+1;k>=2;k--){
				chen*=(long long)k;
				chen%=mod;
			}
			ans+=chen;
		}
		ans%=mod;
		return ;
	}
	if(i==n+1) return ;
	for(int j=1;j<=n;j++){
		if(vis[j]) continue;
		vis[j]=1;
		if(!a[i]){
			num++;
			f(i+1);
			num--;
		}else if(num>=people[j]){
			num++;
			f(i+1);
			num--;
		}else{
			luqu++;
			f(i+1);
			luqu--;
		}
		vis[j]=0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>people[i];
	}
	sort(people+1, people+1+n);
	f(1);
	ans=ans%mod;
	cout<<ans;
	
	return 0;
}
