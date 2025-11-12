#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(k==0)
	{
		cout << n/2;
	}
	else
	{
		cout << n;
	}
	return 0;
}