#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i = (a); i <= (b); i+=(c))
#define per(i,a,b,c) for(int i = (a); i >= (b); i-=(c))
#define ALL(a) (a).begin(), (a).end()
using namespace std;

const int INF = INT_MAX / 2;
const int N = 1e5 + 5;

string s[N], r[N];
bool canUse[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    rep(i,1,n,1) cin >> s[i] >> r[i];
    if(n >= 10000){
    	rep(i,1,m,1) {
    		string a,b;
    		cin >> a >> b;
    		cout << 0 << endl;
		}
		return 0;
	} 
    rep(pp,1,m,1){
        memset(canUse,false,sizeof(canUse));
        int ans = 0;
        string a, b;
        cin >> a >> b;
        rep(i,0,(int)a.size() - 1,1){
            rep(j,1,n,1){
                if(canUse[i]) continue;
                bool can = true;
                rep(k,0,(int)s[j].size() - 1, 1){
                    if(a[i + k] != s[j][k]) can = false;
                }
                if(can){
                    canUse[j] = true;
                    if(s[j] == a) if(r[j] == b) {ans++; continue;}
                    string x = a.substr(0,i);
                    string y = r[j];
                    string z = a.substr(i + (int)s[j].size(), (int)a.size());
                    string tmp = x + y + z;
//
//                    cout <<x <<' ' << y <<' ' << z << endl;
//                    cout <<s[j] <<' '<<r[j]<<' ' << a <<' ' << tmp << endl;cout << endl<<endl;
                    if(tmp == b) ans ++;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

