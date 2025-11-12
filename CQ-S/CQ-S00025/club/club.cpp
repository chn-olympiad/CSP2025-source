#include <bits/stdc++.h>
using namespace std;
int t,n;
const int Max=1e5+5;
int a[Max][3],num[3];
int cnt[Max];
long long prxxx()
{
	long long ans;
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		pair<int,int>res=make_pair(-1,0);
		for(int j=0;j<3;j++)
		{
			res=max(res,make_pair(a[i][j],j));
		}
		cnt[i]==res.second;
		ans+=res.first;
		num[cnt[i]]++;
	}
	for(int ii=0;ii<3;ii++)
	{
		if(num[ii]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(cnt[i]==ii)
				{
					int maxx=0;
					for(int j=0;j<3;j++)
					{
						if(j==ii) 
						{
							continue;
						}
						maxx=max(maxx,a[i][j]);
					}
				}
			}
		}
		for(int i=0;i<3;i++)
		{
			cout<<cnt[i]<<endl;
		}
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j]; 
			}
		}
		cout<<prxxx()<<endl;
	}
	return 0;	
} 

