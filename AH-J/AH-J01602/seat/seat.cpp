#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],cnt;
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
  cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	 for(int i=1;i<=m;i++)
    {
	   	for(int j=1;j<=n*m;j++)
	   	{
			if(a[i]<a[j])cnt++;
		}
	}
  
    int c,r;
    //cnt=(cnt+1)%n;
    cnt=cnt+1;
	/*if((cnt/n)%2==0) && cnt%n!=0)cout<<cnt/n+1<<" "<<cnt%n;
    if((cnt/n)%2==0) && cnt%n==0)cout<<cnt/n+1<<" "<<cnt%n;*/
    if(cnt%n!=0)r=(cnt%n);
    if(cnt%n==0)r=cnt/n-2;
    if(cnt/n!=0)
    {
		if((cnt/n)%n!=0)c=(cnt%n)+2;
	}
    if(cnt/n==0) 
    {
		c=1+(n-1);
    }
    if(n*m==1)cout<<1<<" "<<1;
	else cout<<c<<" "<<r;
	
	
   return 0;
}
