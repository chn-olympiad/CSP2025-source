#include <bits/stdc++.h>
using namespace std;
#define debug cout << "debug: \n";

int n, K;
string k;
int ans;
string s[500010];
//前缀异或和？ 

string i2str(int x) // int to string
{
	string st;
	while(x) {
		st = st + char(x%2+'0');//倒过来方便计算 
		x/=2;
	}
	return st;
}

string xr(string x, string y)//异或 
{
	string st;
	for(int i = 0; i<min(x.size(), y.size()); i++) {
		st = char('0' + ((x[i]-'0')!=(y[i]-'0'))) + st;
//		cout <<x[i]-'0' <<" " << y[i]-'0' <<"\n"<< char('0' + ((x[i]-'0')!=(y[i]-'0'))) <<"\n";
	}
	if(x.size() > y.size()) st = st + x.substr(y.size(), x.size() - y.size());
	if(y.size() > x.size()) st = st + y.substr(x.size(), y.size() - x.size());
	return st;
}

void dfs(int start, int cnt)//暴力美学 好似有亿点超时 
{
	for(int i = start; i<=n; i++) {
		for(int j = i; j<=n; j++) {
			if(xr(s[j], s[i]) == k) {
				dfs(j+1, cnt+1);
				break;
			}
		}
	}
	ans = max(cnt, ans);
}

int cnt_brocken = 114514;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	if(cnt_brocken == 2) cout << "you have no egg!";
	cin >> n >> K;
	k = i2str(K);
	s[0] = "0";
	for(int i = 1; i<=n; i++) {
		int aa;
		cin >> aa;
		string sa = i2str(aa);
		s[i] = xr(s[i-1], sa);
	}
//	debug
//	for(int i = 1; i<=n; i++) {
//		cout << s[i] <<" ";
//	}
//	cout << "\n";
	dfs(1, 0);
	ans++;
	cout << ans << endl;
	return 0;
}
/* ..... ..--- ----- hsh
你猜明天星期几 
mend your pace swape to the beat
hands up embrace who you wana be
we are reaching the hights unseen
woo wo wo~
feel the fire deep within
you are the key where my trust begins
join in my dream it's just the right time
wo wo
leave it all behind
get ready now
riiiiiiiiiiiiiiiiiise
up
into my

woooorld
*/
//TLE了 
