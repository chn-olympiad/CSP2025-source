#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int p[1010];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int ans = 0;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	sort(p+1,p+n+1);
	int id = 1;
	for(int i=2;i<=n;i++)
	{
		if(p[i] != p[i-1]) 
		{
			int len = i-id;
			id = i;
			int temp = 1;
			while(len--)
			{
				temp *= len;
			}
			ans += temp;
		}
	}
	cout<<ans;
	return 0;

}