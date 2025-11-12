#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10086][10086],ans=0,mun=0,b[1000];
int main()
{
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int i=1;i<=2;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				ans=max(a[1][1],a[1][2]);
				ans=max(ans,a[1][3]);
				mun=max(a[2][1],a[2][2]);
				mun=max(mun,a[2][3]);
			}
			b[t]=b[t]+(ans+mun);
			cout<<b[t]<<endl;
	}


	return 0;
 }
