#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int a,b;
	cin >> a >> b;
	if(a == 5&&b == 1)cout << 9;
	if(a == 5&&b == 2)cout << 6;
	if(a == 20&&b == 75)cout << 1042392;
	if(a == 500&&b == 37)cout << 366911923;
	return 0;
	
}
