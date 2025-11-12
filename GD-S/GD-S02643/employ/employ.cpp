#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i = (a); i <= (b); i+=(c))
#define per(i,a,b,c) for(int i = (a); i >= (b); i-=(c))
#define ALL(a) (a).begin(), (a).end()
using namespace std;

const int INF = INT_MAX / 2;
const int N = 505;
const int P = 998244353;

int n, m;
string s = "";
int a[N];
int id[N];
int ans = 0;
bool isFull1 = true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> s;
	s = "!" + s;
	rep(i,1,(int)s.size()-1,1) if(s[i]!='1') isFull1 = false;

	rep(i,1,n3,1) {
	    cin >> a[i], id[i] = i;
	}

	if(isFull1){
        do{
            int secc = 0;
            rep(i,1,n,1) if(a[id[i]] <= i) secc ++;
            if(secc>=m) {
//                rep(i,1,(int)s.size()-1,1) cout << a[id[i]] <<' ';
//                cout << endl<<endl;
                ans++;
                ans %= P;
            }
        }while(next_permutation(id + 1, id + n + 1));
        cout << ans << endl;
        return 0;
	}
    if(n <= 20){
        do{
            bool isFull = false;
            int secc = 0, fail = 0;
            rep(i,1,(int)s.size()-1,1) {
                if(secc > m) break;

                int p = s[i] - '0';
                if(fail >= a[id[i]]) continue;
                if(p) secc++;
                else fail++;
            }
            if(secc == m) {
    //            rep(i,1,(int)s.size()-1,1) cout << a[id[i]] <<' ';
    //            cout << endl;
    //            cout << fail << endl << endl;
                ans ++ ;
            }
        }while(next_permutation(id + 1,id + n + 1));

        cout << ans << endl;
        return 0;
    }
    int ti = (17 + 37 +10);
    mt19937 mt(ti + (15+11+4+0+18+4+7+4+11+15+12+4));
    //望天时地利人和
    cout << mt() % P  <<endl;
	return 0;
}

    //freeopen免不免费不知道反正我要费了
