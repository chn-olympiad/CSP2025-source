#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n],sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		if(a[i] == 1)
		{
			sum++;
		}
	}
	if(sum == n)
	{
		if(n % 2 == 0)
		{
			cout<<n;
		}else
		{
			cout<<n - 1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
111 = 1
1111 = 0
*/

