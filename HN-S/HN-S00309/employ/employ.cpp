#include<bits/stdc++.h>
using namespace std;
int p[505];
int a[505];
int s[505];
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n , m , sum = 0 , num = 0;
	cin >> m;
	for(int i = 0;i <= n;i++)
	{
		if(num > c[i])
		{
			num++;
			sum+=0;
		}
		if(s[i] == 1)
		{
			sum+=0;
			num++;
		}
		else
		{
			sum++;	
		} 
	}
	cout << sum;
	return 0;	
}
