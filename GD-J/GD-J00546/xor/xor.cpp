#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005][2],ans,aans = 1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i =1;i <=n;i++)
	{
		cin >> a[i];
	}
	for(int i =1;i <n;i++)
	{
		for(int j =i+1;j <=n;j++)
		{
			if(k == a[i] | a[j])
			{
				ans++;
				b[ans][1] = i;
				b[ans][2] = j;
			}
		}
	}
	for(int i = 1;i <= ans;i++)
	{
		for(int j = 1;j < ans;j++)
		{
			if((b[j][1] > b[j+1][1]) || (b[j][1] == b[j+1][1] && b[j][2] > b[j+1][2]))
			{
				int t = b[j][1];
				b[j][1] = b[j+1][1];
				b[j+1][1] = t;
				t = b[j][2];
				b[j][2] = b[j+1][2];
				b[j+1][2] = t;
			}
		}
	}
	int tou = b[1][2];
	for(int i = 2;i <= ans;i++)
	{
		if(tou <= b[i][1])
		{
			aans++;
			tou = b[i][2];
		}
	}
	cout << aans;
	return 0;
}
