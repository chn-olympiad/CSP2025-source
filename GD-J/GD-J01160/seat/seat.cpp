#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y)
{
	return x>y;
}
long long n,m,a[1000005],t=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])t=i;
	 } 
	 x=(t+n-1)/n;
	 y=t%n;
	 if(y==0)y=n;
	 if(x%2==0)y=n-y+1;
	 cout<<x<<" "<<y;
	 	
	return 0;
} 
