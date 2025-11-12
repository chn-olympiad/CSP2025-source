#include<bits/stdc++.h>
using namespace std;
int t,maxn=-1,ans,d[205],num=0;
long long n,a[205][5],m[205];

int main()
{
		freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++)
    {
    cin>>n;
	memset(m,0,sizeof(m));
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=maxn) maxn=a[i][j];
			m[i]=maxn;
			d[i]=j;

		}

	}
	for(int i=1;i<=n;i++)
	{
	       m[i]+=m[i-1];
	       ans=m[i];
	}

	cout<<ans<<endl;


	}
	fclose(stdin);
	fclose(stdout);


	return 0;
 }
