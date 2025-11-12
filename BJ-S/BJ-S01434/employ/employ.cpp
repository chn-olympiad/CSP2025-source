#include<bits/stdc++.h>
using namespace std;
int c[100005];
int s[100005];
int b[100005];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)b[i]=i;//标号数组
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;

		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	// sort(c+1,c+n+1,cmp);
	int cnt=0;
	do
	{
		int tmpcnt=0;
		for(int i=1;i<=n;i++)
		{
			if(tmpcnt>=c[b[i]])
			{
				tmpcnt++;
				continue;
			}
			if(!s[i])
			{
				tmpcnt++;
			}

		}
		// cout<<tmpcnt<<endl;
		// for(int i=1;i<=n;i++)
		// {
			// cout<<c[i]
		// }
		if(n-tmpcnt>=m)cnt++;

	}while(next_permutation(b+1,b+n+1));
	cout<<cnt<<endl;
	return 0;
}