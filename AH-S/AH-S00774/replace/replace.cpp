#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans,c[1000][N];
string s[3][N];
bool pd=true;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1; i<=n; i++)
	{
		cin >> s[1][i] >> s[2][i];
		for (int j=0; j<s[1][i].size(); j++)
		{
			if (pd==false)
			{
				break;
			}
			if (s[1][i][j]!='a'&&s[1][i][j]!='b')
			{
				pd=false;
			}
		}
	}
	if (pd)
	{
		int maxx=0,maxs=0,maxxx=0;
		for (int i=1; i<=n; i++)
		{
			int cnt1=0,cnt2=0;
			while (s[1][i][cnt1]=='a')
			{
				cnt1++;
			}
			while (s[2][i][cnt2]=='a')
			{
				cnt2++;
			}
			maxs=max(cnt1,cnt2);
			maxx=max(maxx,maxs);
			maxxx=max(maxxx,cnt1-cnt2);
			c[cnt1-cnt2][maxs]++;
		}
		for (int i=1; i<=maxxx; i++)
		{
			for (int j=1; j<=maxx; j++)
			{
				c[i][j]+=c[i][j-1];
			}
		}
		while (q--)
		{
			string l1,l2;
			cin >> l1 >> l2;
			int cnt1=0,cnt2=0,sum,maxs=0;
			while (l1[cnt1]=='a')
			{
				cnt1++;
			}
			while (l2[cnt2]=='a')
			{
				cnt2++;
			}
			sum=cnt1-cnt2;
			maxs=max(cnt1,cnt2);
			printf("%d\n",c[sum][maxs]);
		}
		return 0;
	}
	while (q--)
	{
		ans=0;
		string l1,l2,sx="",sy="";
		cin >> l1 >> l2;
		int len=l1.size();
		for (int i=0; i<len; i++)
		{
			for (int j=len-1; j>=i; j--)
			{
				for (int k=1; k<=n; k++)
				{
					if (sx+s[1][k]+sy==l1&&sx+s[2][k]+sy==l2)
					{
						ans++;
						break;
					}
				}
				sy="";
				for (int o=j; o<len; o++)
				{
					sy+=l1[o];
				}
			}
			sx+=l1[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
