#include<iostream>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	int a[n+1] = {0};
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	int index = 0;
	int res = 0;
	int cnt = 0;
	
	while(index < n)
	{
		res ^= a[++index];
		if(a[index] == k)
		{
			cnt++;
			res = 0;
		}
		if(res == k)
		{
			cnt++;
			res = 0;
		}
		
	}
	cout << cnt;
	return 0;
}

