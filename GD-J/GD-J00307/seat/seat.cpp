#include <bits/stdc++.h>
using namespace std;
 int n,m,x,y;
 int a[10000];
 bool cmp(int x,int y)
 {
 	return x>y;
 }
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)cin>>a[i];
    int w=a[1];
    sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==w)
		{
			w=i;
			break;
		}
	 }
	 if(w%n==0)x=w/n;
	 else x=w/n+1;
	 
	 if(x%2==1)y=w-(x-1)*n;
	 else 
	 {
	 	int k=w-(x-1)*n;
	 	y=m-k+1;
	  } 
	  cout<<x<<" "<<y;
	return 0;
}
