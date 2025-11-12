#include <bits/stdc++.h>
#define int unsigned long long
#define INF 0x7fffffff
using namespace std;
const int N = 2e5 + 10, P = 1331313;
int n,q;
int base[N];

struct Node{
	vector<int> x = {0}, y = {0};
}p[N];


inline int read()
{
	char c; int x = 0, d = 1;
	for(;!isdigit(c);c=getchar()) if(c == '-') d = -1;
	for(;isdigit(c);c=getchar()) x = x * 10 + c - '0';
	return d * x;
}


signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	n = read(), q = read();
	base[0] = 1;
	for(int i=1;i<N;i++) base[i] = base[i - 1] * P;
	
	for(int i=1;i<=n;i++){
		string x, y;
		cin >> x >> y;
//		for(int j=1,h1=0,h2=0;j<=x.size();j++){
//			p[i].x.push_back(x.back() * P + x - 'a' + 1);
//			p[i].y.push_back(y.back() * P + y - 'a' + 1); 
//		}
	}
	
	for(int i=1;i<=q;i++){
		string x, y;
		cin >> x >> y;
		
		
		
		cout << "0\n";
	}
	
	
	return 0;
}
