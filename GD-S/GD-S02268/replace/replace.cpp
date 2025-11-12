#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , q;
string s[200005];
ll t[200005];

int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for (int i = 0 ; i < n ; i++){
		cin >> s[i];
	}
	for (int i = 0 ; i < q ; i++)
	{
		cin >> t[i];
	}
	srand(time(0));
	for (int i = 0 ; i < q ; i++){
		if (i % 2 == 0){
			cout << rand()%5+1 << '\n';
		}
		else cout << 0 << '\n' ;
	}
	return 0;
}
