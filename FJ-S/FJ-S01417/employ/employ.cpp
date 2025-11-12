#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int c[505];
bool vis[15];
int pw[15];
void dfs(int p) {
	if(p==n+1) {
		int ans=0,kill=0;
		for(int i=1; i<=n; i++) {
			if(s[i-1]=='0') {
				kill++;
			} else {
				if(kill>=c[pw[i]]) {
					kill++;
				} else {
					ans++;
				}
			}
		}
		if(ans>=m) cnt++;
		cnt%=998244353;
	} else {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				pw[p]=i;
				vis[i]=1;
				dfs(p+1);
				vis[i]=0;
			}
		}
	}
}
int pioi(int num) {
	long long kkk=1;
	for(int i=num; i>=1; i--) {
		kkk*=i;
		kkk%=998244353;
	}
	return kkk;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	bool p=1;
	for(int i=0; i<s.length(); i++) {
		if(s[i]!='1')p=0;
	}
	if(n<=15) {
		dfs(1);
		cnt%=998244353;
		cout<<cnt;

	} else if(m==n) {
		if(p){
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					cout<<0;
					return 0;
				}
			}
			cout<<pioi(n);
		}else{
			cout<<0;
		}
	}
}
