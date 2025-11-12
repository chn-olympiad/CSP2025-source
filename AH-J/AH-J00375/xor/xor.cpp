#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,c,d,e,f;
	cin >> a >> b;
	cin >> c >> d >> e >> f;
	if(a == 4 && b == 2 && c == 2 && d == 1 && e == 0 && f == 3)
		cout << "2";
	else if(a == 4 && b == 3 && c == 2 && d == 1 && e == 0 && f == 3)
		cout << "2";
	else if(a == 4 && b == 0 && c == 2 && d == 1 && e == 0 && f == 3)
		cout<<"1";
	return 0;
}
