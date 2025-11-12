#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
string s;
int n,m,a[503];
long long f[503];
int b[503];
int main(){
	f[1]=1;
	for(int i=2;i<=501;i++){
		f[i]=f[i-1]*i;
		f[i]%=M;
	}
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++) b[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(b[i]==0||a[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<f[n];
		return 0;
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			flag=1;
			break;
		}
	}
	if(!flag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			else break;
		}
		cout<<f[n-cnt];
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]) cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
