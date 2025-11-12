#include <bits/stdc++.h>
using namespace std;
int aa[100001], bb[100001], cc[100001], sum[3];
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		sum[0]=sum[1]=sum[2]=0;
		int ans = 0, n;
		cin >> n;
		for(int i = 1; i<=n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			int maxn=max(max(a, b), c);
			if(a==maxn)
			{
				aa[++sum[0]]=min(a-b, a-c);
			}
			else if(b==maxn)
			{
				bb[++sum[1]]=min(b-a, b-c);
			}
			else
			{
				cc[++sum[2]]=min(c-a, c-b);
			}
			ans+=maxn;
		}
		sort(aa+1, aa+sum[0]+1, cmp), sort(bb+1, bb+sum[1]+1, cmp), sort(cc+1, cc+sum[2]+1, cmp);
		while(sum[0]>n/2)
		{
			ans-=aa[sum[0]];
			sum[0]--;
		}
		while(sum[1]>n/2)
		{
			ans-=bb[sum[1]];
			sum[1]--;
		}
		while(sum[2]>n/2)
		{
			ans-=cc[sum[2]];
			sum[2]--;
		}
		cout << ans << endl;
	}
	return 0;
}
