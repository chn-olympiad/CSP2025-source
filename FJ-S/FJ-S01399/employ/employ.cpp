#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	char a[505];
	int b[505];
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >>b[i];
	}
	int cnt  = 0;
	bool f4 = 0;
	for(int i = n-1;i > 0;i--)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for(int j  = 1;j <= n;j++)
		{
			if(a[j]=='1'&&b[j]>cnt2)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		if(cnt1>=m)
		{
			cnt++;
		}
		if(cnt2 > b[n]&&!f4)
		{
			f4 = 1;
		}
		if(cnt2>b[i]&&f4)
		{
			int temp = 0;
			temp = b[1+i];
			b[i+1]=b[i];
			b[i]=temp;
		}
	}
	cout<<cnt;
	return 0;	
} 
