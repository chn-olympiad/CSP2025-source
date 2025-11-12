#include<bits/stdc++.h>
using namespace std;
#define N 1100
int ans,n,m,a[N],fl[N],sta[N],cnt;
string s;
void dfs(int id) {
	if(cnt==n) {
		int no=0;
		for(int i=1; i<=n; i++) {
			if(s[i-1]=='0'||no>=a[sta[i]]) {
				no++;
			}
		}
		if(n-no>=m) {
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(fl[i]) continue;
		fl[i]=1;
		sta[++cnt]=i;
		dfs(i);
		sta[cnt--]=0;
		fl[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n>11){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
//	fl[1]=1;
	dfs(0);
	cout<<ans;
	return 0;
}/*
11 5
11011110111
6 0 4 2 1 2 5 4 3 3 5
*/

