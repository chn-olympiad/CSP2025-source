#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int N = 5e6+10;
int n,q;
int fir[N][3];
int op[N];
int sec[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	rep(i,1,n){
		string s;
		cin>>s;
		rep(sz,0,s.size() - 1){
			if (s[sz] == 'b'){
				fir[i][1] = sz;
				sec[i][1] = s.size()-sz-1;
			}
		}
		cin >> s;
		rep(sz,0,s.size() - 1){
			if (s[sz] == 'b'){
				fir[i][2] = sz;
				sec[i][2] = s.size()-sz-1;
			}
		}
		op[i] = fir[i][1] - fir[i][2];
	}
	rep(i,1,q){
		int cnt = 0;
		string a, b;
		cin >> a >> b;
		int fir1,fir2,sec1,sec2;
		rep(sz,0,a.size() -1){
			if (a[sz] == 'b') {
				fir1 = sz;
				sec1 = a.size() - sz - 1;
			}
		}
		rep(sz,0,b.size() -1){
			if (b[sz] == 'b') {
				fir2 = sz;
				sec2 = b.size() - sz - 1;
			}
		}
		int opp = fir1-fir2;
		rep(j,1,n){
			if (opp == op[1] && fir[i][1] <= fir1 && sec[i][1] <= sec1) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}

