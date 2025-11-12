//100pts
#include<bits/stdc++.h>
//bool Mst;
#define ll long long
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N], cnt;

//bool Med;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cerr << abs((&Mst)-(&Med)) / 1024.0 / 1024 << "MB" << '\n';
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto i:s){
		if(i >= 'a' && i <= 'z') continue;
		a[++cnt] = i - '0';
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i; --i) cout << a[i];
	
	return 0;
} 
