#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int c[503],n,m,ans;
char s[505];
char ss1[12];
map<char,int> mp;
bool vis[100];
void dfs(int id,char num[12]) {
	char tmp[12];
	for(int i=1; i<=11; i++) {
		tmp[i]=num[i];
	}
	if(id==n) {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				vis[i]=true;
				tmp[id]=(i+'0');
				vis[i]=false;
			}
		}
		int fail=0;
		for(int i=1; i<=n; i++) {
			int x=mp[tmp[i]];
			if(fail>=c[x]) {
				fail++;
				continue;
			}
			if(s[i]=='0') {
				fail++;
				continue;
			}


		}
		if(n-fail>=m) {
			ans++;
		}

		return ;
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=true;
			tmp[id]=(i+'0');
			dfs(id+1,tmp);
			tmp[id]=0;
			vis[i]=false;
		}
	}
	return ;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	mp['1']=1;
	mp['2']=2;
	mp['3']=3;
	mp['4']=4;
	mp['5']=5;
	mp['6']=6;
	mp['7']=7;
	mp['8']=8;
	mp['9']=9;
	mp[':']=10;

	cin>>n>>m;
	cin>>(s+1);
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	
	dfs(1,ss1);
	cout<<ans%MOD;
	return 0;
}
