#include<bits/stdc++.h>
using namespace std;
int n,q,ans,w[205000],x,y,start,finish,flag;
string a[5005000],b[5005000],th[205000],thh[205000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>th[i]>>thh[i];
		ans=int(thh[i].size());
		w[i]=ans;
	}
	if(n>=20000)
	{
		for(int i=1;i<=q;i++) cout<<0<<"\n";
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>a[i]>>b[i];
		x=a[i].size();
		y=b[i].size();
		if(x!=y) {cout<<0<<"\n";continue;}
		start=100000000,finish=0;
		for(int j=0;j<x;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				start=min(start,j);
				finish=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(w[j]>=finish-start+1&&w[j]<=x&&th[j]!=thh[j])
			{
				for(int k=0;k<x-w[j]+1;k++)
				{
					if(a[i][k-1]!=b[i][k-1]) break;
					flag=0;
					if(a[i][k]==th[j][0]&&b[i][k]==thh[j][0])
					{
						for(int l=k;l<k+w[j];l++)
						{
							if(a[i][l]!=th[j][l-k]||b[i][l]!=thh[j][l-k])
							{
								flag=1;
								break;
							}
						}
						if(!flag){ans++;break;}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}