#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010][3],b[3][2];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int kk=1;kk<=t;kk++)
	{
		int h=0;
		cout<<h;
		for(int i=1;i<=100010;i++)
			for(int j=1;j<=3;j++)
				a[i][j]=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=2;j++)
				b[i][j]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			int d=-2e9,dh;
			for(int j=1;j<=3;j++)
				if(d<a[i][j]){d=a[i][j];dh=j;}
			if(b[dh][1]<=n/2){b[dh][2]+=d;b[dh][1]++;}
		}
		for(int i=1;i<=3;i++)
			h+=b[i][2];
		cout<<h<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
