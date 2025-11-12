#include <bits/stdc++.h>
using namespace std;
long long T;
long long n;
struct Node
{
	long long x,y,z;
} a[100005];
long long minn1[500005];
long long minn2[500005];
long long minn3[500005];
long long ans1 = 0,ans2 = 0,ans3 = 0;
long long start1 = 1,start2 = 1,start3 = 1;
long long ans = 0;
long long pos1 = 0,pos2 = 0,pos3 = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(a,0,sizeof(a));
		memset(minn1,0,sizeof(minn1));
		memset(minn2,0,sizeof(minn2));
		memset(minn3,0,sizeof(minn3));
		ans1 = 0,ans2 = 0,ans3 = 0;
		start1 = 1,start2 = 1,start3 = 1,pos1 = 0,pos2 = 0,pos3 = 0;
		ans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for (int i = 1;i <= n;i++)
		{
			long long u = max(a[i].x,max(a[i].y,a[i].z));
			long long v = min(a[i].x,min(a[i].y,a[i].z));
			if (a[i].x >= a[i].y && a[i].x >= a[i].z)
			{
				ans1++;
				minn1[++pos1] = 2 * u + v - (a[i].x + a[i].y + a[i].z);
			}
			else if (a[i].y >= a[i].x && a[i].y >= a[i].z)
			{
				ans2++;
				minn2[++pos2] = 2 * u + v - (a[i].x + a[i].y + a[i].z);
			}
			else if (a[i].z >= a[i].x && a[i].z >= a[i].y)
			{
				ans3++;
				minn3[++pos3] = 2 * u + v - (a[i].x + a[i].y + a[i].z);
			}
			ans += u;
			if (ans1 > n / 2)
			{
				sort(minn1 + start1,minn1 + pos1 + 1);
				ans -= minn1[start1++];
				ans1--;
			}
			else if (ans2 > n / 2)
			{
				sort(minn2 + start2,minn2 + pos2 + 1);
				ans -= minn2[start2++];
				ans2--;
			}
			else if (ans3 > n / 2)
			{
				sort(minn3 + start3,minn3 + pos3 + 1);
				ans -= minn3[start3++];
				ans3--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
