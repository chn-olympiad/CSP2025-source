#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],i,j,x,hang,lie;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	    cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for(i=n*m;i>=1;i--)
	{
		j++;
	    if(a[i]==x)
	        break;
	}
	    
	if(j%n==0)
	    lie=j/n;
	else
	    lie=j/n+1;
	if(lie%2==1)
	    hang=j-(lie-1)*n;
	else
	    hang=n-(j-(lie-1)*n)+1;
	cout<<lie<<" "<<hang;
	return 0;
}