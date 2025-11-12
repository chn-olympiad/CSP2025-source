# include <algorithm>
# include <iostream>
# define FILE
using namespace std;
int n,m,st[15][15];
struct stu{ int sc,id; }s[105];
void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> s[i].sc;
		s[i].id = i;
	}sort(s + 1,s + 1 + n * m,[](stu a,stu b){ return a.sc > b.sc; });
	for (int i = 1,x = 1,y = 1;i <= n * m;i++){
		if (s[i].id == 1){
			cout << x << " " << y << "\n";
			return;
		}if (x & 1){
			y++;
			if (y > n) y = n,x++;
		}else{
			y--;
			if (y < 1) y = 1,x++;
		}
	}
}int main(){
    # ifdef FILE
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    # endif
    # ifdef mulq
    int T; cin >> T;
    while (T--) solve();
    # else
    solve();
    # endif
    return 0;
}
