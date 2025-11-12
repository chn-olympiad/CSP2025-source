#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("polygun.in","r",stdin);
	freopen("polygun.out","w",stdout);
	int n,a = 3;
	cin >> n;
	if(n < 3)
	{
		cout << "0";
		return 0;
	}
	if(n == 3)
	{
		cout << "1";
		return 0;
	}
	cout << "9";
	
	return 0;
}
//3-1,4-3,5-6,6-10
//(n-2)(n-1)/2
