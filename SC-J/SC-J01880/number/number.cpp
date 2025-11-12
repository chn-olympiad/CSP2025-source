#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
long long arr[10];
int main()
{
	
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	int p = n.size();
	
	for (int i = 0;i < p;i++)
	{
		if (n[i] <= '9' && n[i] >= '0') 
		{
			int m = int(n[i]-'0');
			arr[m]++;
		}
	}
	for (int i = 9;i >= 0;i--) 
	{
		for (int j = 0;j < arr[i];j++) cout << i;
	}
	return 0;
}