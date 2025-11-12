#include<bits/stdc++.h>
using namespace std;
int a[500005]; 
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	 
	int n, k;
	bool A = 1, B = 1, C = 1; //ÌØÊâÐÔÖÊ 
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		if(a[i] != 1)A = 0;
		if(a[i] > 1)B = 0;
		if(a[i] > 225)C = 0; 
	}
	if(A)
	{
		if(k == 0)cout << n / 2 << endl; 
		else if(k == 1)cout << n << endl;
		else cout << 0 << endl;
	}
	else if(B)
	{
		if(k == 0)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] == 0)cnt ++;
				else if(a[i] == a[i + 1] && a[i])
				{
					cnt ++;
					i ++;
				}
			}
			cout << cnt << endl;
		}
		else if(k == 1)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(a[i])cnt ++;
			}
			cout << cnt << endl;
		}
		else cout << 0 << endl;
	}
	else if(C)
	{
		
	}
	else
	{
		
	}
	return 0;
}
