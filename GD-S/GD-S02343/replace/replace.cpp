#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;
string s[N],s1[N],s2[N],t;
ll cnt,a[N][2],b[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> s[i];
		int l = s[i].size();
		int j = 0;
		int f = 1;
		for(j; j < l; ++j){
			if(s[i][j] == ' ') break;
			s1[i] += s[i][j];
			if(s[i][j] == 'b'){
				f = 0;
				continue;
			}
			if(f) ++a[i][0];
			else ++a[i][1];
		}
		f = 1;
		for(j = j + 1; j < l; ++j){
			s2[i] += s[i][j];
			if(s[i][j] == 'b'){
				f = 0;
				continue;
			}
			if(f) ++b[i][0];
			else ++b[i][1];
		}
	}
	while(q--){
		cin >> t;
		int ans = 0;
		int l = t.size();
		int f = 1;
		int c1 = 0,c2 = 0;
		for(int i = 0; i < l; ++i){
			if(t[i] == 'b'){
				f = 0;
				continue;
			}
			if(f){
				++c1;
			}else ++c2;
		}
		for(int i = 1; i <= n; ++i){
			if(a[i][0] <= c1 && a[i][1] <= c2 && b[i][0] <= c1 && b[i][1] <= c2) ++ans;
		}
		cout << ans << endl; 
	}
	return 0;
}
