#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin >> n >> m;
	string s;cin >> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0){
			cout << 0;
			return 0;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			cout << 0;
			return 0;
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++)ans*=i,ans%=mod;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
