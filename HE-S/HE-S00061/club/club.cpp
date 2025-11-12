#include<bits/stdc++.h>
using namespace std;
int sd[300010];
int a[300010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int m=1,ans=0,cnt=0;
		bool flag=false;
		int n;
		cin>>n;
		for(int j=1;j<=n*3;j++)
			cin>>sd[j];
		for(int i=1;i<=n*3;i++)
		{
			if(sd[i])
			{
				a[m]=sd[i];
				m++;
				flag=true;
			}
			else
				cnt++;
		}
		if(flag)
		{
			sort(a+1,a+m+1,cmp);
			int c=n/2;
			for(int x=1;x<=c;x++)
				ans+=a[x];
			cout<<ans;				
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
