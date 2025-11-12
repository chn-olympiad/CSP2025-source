#include <bits/stdc++.h>
using namespace std;
long long a[5000],n,m,ans=0;
bool b[5000];
long long g[5000];
long long f[5000];
void dfs(int pos){
	if(pos>n){
		int sum=0,k=0;
		for(int i=1;i<=n;i++){
			if(k>=g[i]){
				k++;
				continue;
			}
			if(f[i]==1)sum++;
			else k++;
		}
		if(sum>=m){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			b[i]=true;
			g[pos]=a[i];
			dfs(pos+1);
			g[pos]=0;
			b[i]=false;
		}
	}
}
bool r=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f[i+1]=0,r=0;
		else f[i+1]=1;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0)i--,n--;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(f[i]==0){
				cout << 0 << endl;
				return 0;
			}
		}
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout << ans << endl;
		return 0;
	}
	if(n<m){
		cout << 0 << endl;
		return 0;
	}
	if(r){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout << ans << endl;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0; 
}
