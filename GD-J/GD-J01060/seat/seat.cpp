#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],r,ord;
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
		{
			ord=i;
			break;
		}
	if(ord%n==0)
		if(((ord/n)%2)==1)
			if(ord%n==0)
				cout<<ord/n<<" "<<n;
			else
				cout<<ord/n<<" "<<ord%n;
		else
			if(ord%n==0)
				cout<<ord/n<<" "<<1;
			else
				cout<<ord/n<<" "<<n-(ord%n)+1;
	else
		if((ord/n+1)%2==1)
			if(ord%n==0)
				cout<<ord/n+1<<" "<<n;
			else
				cout<<ord/n+1<<" "<<ord%n;
		else
			if(ord%n==0)
				cout<<ord/n+1<<" "<<1;
			else
				cout<<ord/n+1<<" "<<n-(ord%n)+1;
	return 0;
 } 
