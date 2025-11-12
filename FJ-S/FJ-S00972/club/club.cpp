#include<bits/stdc++.h>
using namespace std;
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
		int a[1000],b[1000],c[1000],maxs[1000]={0},m=n/2;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		int sum=0,cnt=1,cut=1,kut=1;
		for(int i=1;i<=n;i++)
		{
			int maxss=0;
			maxss=max(a[i],maxss);
			maxss=max(b[i],maxss);
			maxss=max(c[i],maxss);
			if(cnt<=m && maxss==a[i])
			{
				cnt++;
				maxs[i]=maxss;
			}
			else if(cnt>m && maxss==a[i])
			{
				bool f=0;
				for(int j=1;j<=n;j++)
				{
					if(maxs[j]==a[j] && maxs[j]<maxss)
					{
						maxs[j]=maxss;
						f=1;
						break;
					}
				}
				if(f==0)
				{
					maxss=max(b[i],c[i]);
					maxs[i]=maxss;
				}
			}
			if(cut<=m && maxss==b[i])
			{
				cut++;
				maxs[i]=maxss;
			}
			else if(cut>m && maxss==b[i])
			{
				bool f1=0;
				for(int j=1;j<=n;j++)
				{
					if(maxs[j]==b[j] && b[j]<b[i])
					{
						maxs[j]=b[i];
						f1=1;
						break;
					}
				}
				
				if(f1==0)
				{
					maxss=max(a[i],c[i]);
					maxs[i]=maxss;
				}
				
			}
			if(kut<=m && maxss==c[i])
			{
				kut++;
				maxs[i]=maxss;
			}
			else if(kut>m && maxss==c[i])
			{
				bool f2=0;
				for(int j=1;j<=n;j++)
				{
					if(maxs[j]==c[j] && maxs[j]<maxss)
					{
						maxs[j]=maxss;
						f2=1;
						break;
					}
				}
				if(f2==0)
				{
					maxss=max(a[i],b[i]);
					maxs[i]=maxss;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			sum+=maxs[i];
		}
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
