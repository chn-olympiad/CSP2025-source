#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int maxn=-2e9,maxn1=-2e9,maxn2=-2e9;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		int cnt=0;
		for(int i=1;i<=n/2;i++)
		{
			cnt+=a[i];
		}
		cout << cnt;
	}
	return 0;
}