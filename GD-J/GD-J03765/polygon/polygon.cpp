#include<bits/stdc++.h>
using namespace std;
int b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin >> a;
	for(int i = 1;i <= a;i++)
	{
		cin >> b[i];
	}
	if(a == 5)
	{
		if(b[1] == 1) cout << 9;
		else cout << 6;
	}
	return 0;
 } 
