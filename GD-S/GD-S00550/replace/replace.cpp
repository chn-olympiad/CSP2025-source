#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
int nxt[123123],ans;
string cut[1006][1006];
void getnxt(string x){
	int i = 1,j = 0,len = x.length();
	nxt[0] = -1;
	while(i < len)
		if(j == -1 || x[i] == x[j]){
			i++,j++;
			nxt[i] = j;
		}else j = nxt[j];
}
bool f = 0;
void kmp(string x,string y,string change,string need){
	int i = 0,j = 0,lenx = x.length(),leny = y.length();
	if(f) return ;
	if(x == need){
		f = 1;
		ans++;
		return ;
	}
	while(i < lenx)
		if(j == -1 || x[i] == y[j]){
			i++,j++;
			if(j == leny){
				kmp(cut[0][i] + change + cut[change.size() + 1][x.size() - change.size() + 1],y,change,need);
				kmp(x,y,change,need);
				j = 0;
			}
		}else j = nxt[j];
}
void solve(){
	int n,m;
	cin >> n >> m;
	vector<string> x(n + 1),y(n + 1);
	for(int i = 1;i <= n; i++)
		cin >> x[i] >> y[i];
	while(m--){
		ans = 0;
		string X,Y;
		cin >> X >> Y;
		for(int i = 0;i < X.size(); i++) cut[i][i] = "";
		for(int i = 0;i < X.size(); i++) cut[i][i] += X[i];
		for(int i = 0;i < X.size(); i++){
			for(int j = i + 1;j < X.size(); j++) 
				cut[i][j] = cut[i][j - 1] + X[j];
		}
		for(int i = 1;i <= n; i++){
//			f = 0;
			getnxt(x[i]);
			kmp(X,x[i],y[i],Y);
		}
		cout << ans << endl;
	}
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T = 1;
	while(T--)
		solve();
}
