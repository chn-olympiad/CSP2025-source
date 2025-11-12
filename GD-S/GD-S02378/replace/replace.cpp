#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("replace.in");
ofstream cout("replace.out");
string tf[200000], tt[200000], f, t;
int n, q, ans, pos;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i=0; i<n; i++)
		cin >> tf[i] >> tt[i];
	while(ans = 0, q--){
		cin >> f >> t;
		for(int i=0; i<n; i++){
			pos = f.find(tf[i]);
			if(pos == f.npos) continue;
			if(f.substr(0, pos) + tt[i] + f.substr
			(pos + tt[i].size()) == t) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
