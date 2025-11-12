#include <bits/stdc++.h>
using namespace std;

struct location
{
	int left,right;
}loc[15];

bool cmp(location a,location b)
{
	return a.left < b.left;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,num[100005],ans = 0;
	cin >> n >> k;
	for(long long i = 1;i <= n;i++)
		cin >> num[i];
	long long lnum = 0;
	if(n == 2)
	{
		if(num[1] == k) ans++;
		if(num[2] == k) ans++;
		if((num[1] | num[2]) == k && num[1] != k && num[2] != k) ans++; 
		cout << ans;
		return 0;
	}
	if(n == 1)
	{
		if(num[1] == k) cout << 1;
		return 0;
	}
	long long count = 1;
	for(long long l = 1;l <= n;l++)
	{
		for(long long r = l;r <= n;r++)
		{
			int numl = 0;
			for(long long i = l + 1;i <= r;i++)
				numl += (num[i - 1] | num[i]);
			if(numl == k)
			{
				loc[count].left = l;
				loc[count].right = r;
				count++;
			}
		}
	}
	sort(loc + 1,loc + count + 1,cmp);
	for(int i = 2;i <= count;i++)
	{
		if(loc[i].left <= loc[i - 1].right) continue;
		ans++;
	}
	cout << ans;
	return 0;
}
