#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105];
int z[105][105];
int m[105][105];
int q=0,qq=0,qqq=0,qqqq=0;
int vvvv=0;
int h=0,hh=0;
int l;
int t;
int k;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,p;
	int s=0; 
	cin>>n>>p;
	s=p/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
	        cin>>a[i][j];
	        q=a[1][1];
	        qq=a[2][2];
	        qqq=a[3][3];
	        qqqq=a[3][3];
	    }
	}
	t=q+qq+qqq+qqqq;
	cout<<t<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
	        cin>>z[i][j];
	        vvvv=z[1][1];
	    }
	}
	l=vvvv;
	cout<<l<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
	        cin>>m[i][j];
	        h=m[2][2];
	        hh=z[1][1];
	    }
	}
	k=h+hh;
	cout<<k;
	return 0;
}
