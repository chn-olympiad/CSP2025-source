#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pint pair<int,int>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define fst first
#define snd second
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)

const int N = 2e5 + 5;
int n,q;
string s[N][2];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	FRR("in.txt");
//	FRW("mine.txt");
	FRR("replace.in");
	FRW("replace.out");
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string s1,s2; cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			cout << 0 << "\n";
			continue;
		}
		int n = s1.size(), ans = 0;
		s1= " " + s1, s2 = " " + s2;
		for(int i=1;i<=n;++i){
			int m = s[i][0].size();
			for(int j=1;j<=n-m+1;++j){
				string tmp = s1.substr(j,m);
				if(tmp == s[i][0] && s1.substr(0,j)+s[i][1]+s1.substr(j+m) == s2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	
	
	return 0;
}

