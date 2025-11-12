#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],p;
long long ans=0;
void solv(int i,long long s,int i1,int i2,int i3)
{
	if(i>n) {
		ans=max(ans,s);
	}
	else {if(i1<p)solv(i+1,s+a[i][1],i1+1,i2,i3);
	      if(i2<p)solv(i+1,s+a[i][2],i1,i2+1,i3);
	      if(i3<p)solv(i+1,s+a[i][3],i1,i2,i3+1);
	} 
}
int main()
{   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {   long long sum=0;
        ans=0;
        scanf("%d",n);
    	p=n/2;
    	for(int j=1;j<=n;j++)
    	   {
		   scanf("%d,%d,%d",a[j][1],a[j][2],a[j][3]);
		   }
		solv(0,sum,0,0,0);
		cout<<ans;
	}
	return 0;
}