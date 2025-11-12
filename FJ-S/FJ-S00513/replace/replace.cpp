#include <bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
int n,m;
const int maxn=205;
map<string,string> q;
map<string,bool> vis;
inline bool check(string a,string b){
	int r=a.length();
	for(re int i=0;i<r;i++){
		if (a[i]!=b[i]) return false;
	}
	return true;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(re int i=1;i<=n;i++){
		string a,b;
		cin >> a >> b;
		vis[a]=1;
		q[a]=b;
	}
	while(m--){
		int ans=0;
		string s;
		string w;
		cin >> s >> w;
		cout << s << endl << w << endl;
		int l=s.length();
		for(re int i=0;i<l;i++){
			for(re int j=i;j<l;j++){
				string val;
				for(re int k=i;k<=j;k++) val=val+s[k];
				if (vis[val]){
					val=q[val];
					string op;
					for(re int k=0;k<=i-1;k++) op=op+s[k];
					string aim=op+val;
					for(re int k=j+1;k<=l;k++) aim=aim+s[k];
					if (check(aim,w)) ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
