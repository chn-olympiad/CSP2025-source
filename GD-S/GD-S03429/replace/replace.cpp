#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
string a,b;
string s[N][2];
bool check(string x,string y){
	int cnt = 0;
	for(int i = 0;i < x.length();i++)
		cnt += (x[i] != 'a') + (y[i] != 'a');
	return cnt == 2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s[i][0] >> s[i][1];
	while(q--){
		int ans;
		cin >> a >> b;
		if(a.length() != b.length()){
			cout << 0 << '\n';
			continue; 
		}
		int st = -1, ed = -1;
		for(int i = 0;i < a.length();i++)
			if(a[i] != b[i]){
				st = i; break;
			}
		for(int i = a.length() - 1;i >= 0;i--)
			if(a[i] != b[i]){
				ed = i; break;
			}
		string str,str1;
		if(st == -1){
			str = a; str1 = a;
			ans = 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
