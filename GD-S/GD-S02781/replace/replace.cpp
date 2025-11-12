#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct point{
	string a,b;
}d[200005];
void work(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> d[i].a >> d[i].b;
	}
	for(int i = 1;i <= m;i++){
		string s,t;
		cin >> s >> t;
		int len = s.size();
		int cnt = 0;
		for(int j = 1;j <= n;j++){
			string r = d[j].a,p = d[j].b;
			int pos = s.find(r,0);
			while(pos != -1){
				if(pos == -1) break;
				string a = "",b = p,c = "";
				for(int k = 0;k < pos;k++) a = a + s[k];
				int l1 = r.size();
				for(int k = pos + l1;k < len;k++) c = c + s[k];
				if(a + b + c == t) cnt++;
				pos = s.find(r,pos+1);
			}
		}
		cout << cnt << endl;
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}

