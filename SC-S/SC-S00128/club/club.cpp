#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100][5],Js,b[100100],LoVe[10],c[100100],f1=-1,f2=-2,tt;
long long ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int qqq=1;qqq<=t;qqq++)
	{
		ans=0;
		LoVe[1]=0;
		LoVe[2]=0;
		LoVe[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			f1=-1;
			f2=-2;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>f1)
				{
					f2=f1;
					f1=a[i][j];
					c[i]=j;
					continue;
				}
				if(a[i][j]>f2)
				{
					f2=a[i][j];
				}
			}
			LoVe[c[i]]++;
			ans+=f1;
			b[i]=f1-f2;
		}
		Js=n/2;
		for(int i=1;i<=3;i++)
		{
			if(LoVe[i]>Js)
			{
				Js=LoVe[i]-Js;
				tt=0;
				for(int j=1;j<=n;j++)
				{
					if(c[j]==i)
					{
						tt++;
						c[tt]=b[j];
					}
				}
				sort(c+1,c+tt+1);
				for(int j=1;j<=Js;j++)
				{
					ans-=c[j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}