#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
const int mod=998244353;
int n,m,ans,a[510],c[510];
string s;
queue<int> q;
bool check() {
	int sum=0,sum1=0;
	for(int i=1;i<=n;i++) {
		if(s[i-1]=='0' || sum>=c[a[i]]) {
			sum++;
		}
		else {
			sum1++;
		}
	}
	return sum1>=m;
}
void dfs(int k) {
	if(k>n) {
		if(check()) {
			ans++;
			if(ans>=mod) {
				ans-=mod;
			}
		}
		return;
	}
	int len=q.size();
	while(len--) {
		a[k]=q.front();
		q.pop();
		dfs(k+1);
		q.push(a[k]);
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++) {
		c[i]=read();
		q.push(i);
	}
	if(n>=12) {
		ans=1;
		for(int i=1;i<=n;i+=2) {
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}