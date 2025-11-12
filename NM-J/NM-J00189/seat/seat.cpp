#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[400]={0},c[20][20],r=0,o,p,m=1,s=0;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=1;
    cin>>o>>p;
    for(int i=1;i<=o;i++)
    {
		for(int j=1;j<=p;j++)
		{
			cin>>a[i][j];c[i][j]=a[i][j];
		}
    }
    s=o*p;
    for(int k=1;k<=s;k++)
    {
		for(int i=1;i<=o;i++)
        {
		    for(int j=1;j<=p;j++)
			{
				if(a[i][j]>b[n]) b[n]=a[i][j];
				
			}
		 }
		 for(int i=1;i<=o;i++)
		 {
			 for(int j=1;j<=p;j++)
			 {
				if(b[n]==a[i][j]) a[i][j]=0;
			 }
		 }
		 n++;
	}
    for(int i=1;i<=s;i++)
    {
		 if(b[i]==c[1][1])
		 {
			 r=i;break;
		 }
	}int t=r;
    for(int i=1;i<=o;i++)
    {
		 if(t>p) m++,t-=p;
    }
    if(m%2==0) r=p-t+1;
    else r=t;
    cout<<m<<" "<<r;
    return 0;
}
