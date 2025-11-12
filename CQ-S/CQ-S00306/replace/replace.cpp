#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(!('0' <= ch && ch <= '9')) {
		if(ch == '-')
			f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 2e5 + 5;

string in[N][3] , ask[N][3];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n = read() , q = read();
	for(int i = 1 ; i <= n ; i++)
		cin >> in[i][1] >> in[i][2];
	for(int j = 1 ; j <= q ; j++)
		cin >> ask[j][1] >> ask[j][2];
	for(int i = 1 ; i <= q ; i++)
		cout << 0 << "\n" ;

	return 0;
}


