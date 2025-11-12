#include  <bits/stdc++.h>
using namespace std;
string a[1050],b[1050],c[1050],d[1050];
string a1[1050],b1[1050],c1[1050],d1[1050];
int x=0;
int ans,cnt,ji[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],a1[i]=a[i],b1[i]=b[i];
	for(int i=1;i<=q;i++)cin>>c[i]>>d[i],c1[i]=c[i],d1[i]=d[i];
	for(int i=1;i<=n;i++)
	{
		while(a[i][x]!=0)
		{
			x++;
			ji[i]++;
		}
		x=0;
	}
//	cout<<ji[1]<<" "<<ji[2];
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;;k++)
			{
				if(a[j][k]==0)break;
				if(a[j][k]==c[j][x])
				{
					int pan=j,dan=k,an=x;
					while(1)
					{
						if(a[j][dan]!=c[j][an] || a[j][dan]==0 || c[j][an]==0)
						{
							break;
						}
						else
						{
							a1[j][dan]=b[j][an];
							dan++;
							an++;
							cnt++;
						}
					}
					if(cnt==ji[j])ans++;
					/*
					if(a1[j]==b[j])
					{
						ans++;
						cout<<a1[j]<<" "<<b[j]<<endl;	
						a1[j]=a[j];
					}
					else a1[j]=a[j];*/
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		cnt=0;
	}

 	return 0;
}

