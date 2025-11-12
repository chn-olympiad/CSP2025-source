#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sum[505],cnt,ans;
string s;
struct node
{
	int a,b;
}c[505];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		c[i].a=i;
		cin>>c[i].b;
		if(s[i-1]==0)
		{
			sum[i]=cnt;
			cnt++;
		}
		else
		{
			sum[i]=cnt;
		}
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(c[i].b>sum[j]&&c[j].b>sum[i])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
