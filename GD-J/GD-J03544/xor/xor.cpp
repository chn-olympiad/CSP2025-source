#include<bits/stdc++.h>
using namespace std;
const int MN=5e5+10;
int n, k, ans;
int a[MN], s[MN];
bool isok(int i, int j)
{
	return int(s[i-1]^s[j]) == k;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s[i]=int(s[i-1]^a[i]);
	}
	int x=1, y=1;
	while(x<=y && x<=n)
	{
		if(y>n)
		{
			y=x;
			x++;
		}
		if(isok(x, y))
		{
			ans++;
			x=y+1;
		}
		y+=1;
	}
	cout << ans;
	return 0;
}
