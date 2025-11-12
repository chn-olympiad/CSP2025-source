#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int abss[maxn];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin >> a;
	int len;
	for(int i = 1;i <= a;i++)
	{
		cin >> abss[i];
		len = abss[i] + abss[i - 1];
	}
	cout << len << endl;
	return 0;
}
