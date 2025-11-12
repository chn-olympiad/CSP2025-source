#include<bits\stdc++.h>
using namespace std;
int a[150],n,m,l,r,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];	
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==l){
			r=n*m-i+1;
			break;
		}
	}
	
	if(r%n==0)  p=r/n;
	else p=r/n+1;
	cout<<p<<" ";
	p--;
	if(p%2==1){
		if(r%n==0)  cout<<n;
		else  cout<<n-r%n+1;
	}
	else if(r%n==0)  cout<<n;
	else cout<<r%n;
	return 0;
} 

