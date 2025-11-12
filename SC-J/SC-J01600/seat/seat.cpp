#include<bits/stdc++.h>
using namespace std;
int m,n,a[101],w=1,am,an;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		  w++;
	}
	if(w%n==0)
	  am=w/n;
	else
	  am=w/n+1;
	if(am%2==1)
		an=w-n*(am-1);
	else
		an=n-(w-n*(am-1))+1;
	cout<<am<<' '<<an;	
	return 0;
 } 