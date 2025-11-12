#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int zw[15][15]={0};
int id;
int nm=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
   {
       cin>>a[i];
   }
   id=a[1];
   sort(a+1,a+1+n*m,cmp);
   for(int i=1;i<=m;i++)
   {
   	
   	if(i%2==1)
   	{
	    int cntd=1;
   		while(cntd<=n)
   		{
   			zw[cntd][i]=a[nm];
   			
   			nm++;
   			cntd++;
		}
	}
	else if(i%2==0)
	{
		int cntf=n;
		while(cntf>0)
		{
			zw[cntf][i]=a[nm];
			
   			nm++;
   			cntf--;	
		}
	}
   }
   for(int i=1;i<=n;i++)
   {
   	for(int j=1;j<=m;j++)
   	{
   	    if(zw[i][j]==id)
   	    {
   	    	cout<<j<<" "<<i;
		}
	}
   }
}
