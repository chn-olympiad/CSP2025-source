#include<bits/stdc++.h>
using namespace std;
int a[1001][10001];
int main()
{
	int cnt=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int sum=0;
	int a;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<3;j++)
		{
		scanf("%d",&a[i][j]);
		cnt++;
			if(cnt==1);
			{
			int b=a;
			}
			if(cnt==2)
			{
			int c=a;
			}
			if(cnt==3)
			{																																																																																																																						
			int d=a;
			continue;
						}
			if(e==f)
		sum	+=c;
			int e=max(b,c);
			int f=max(c,d);
			int g=max(d,b);
			if(f==g)
			sum+=d;
			if(e==g)
			sum+=b;
				}
		}
}
	cout<<sum<<endl;
	return 0;
}

	
