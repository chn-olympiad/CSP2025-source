#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],littelR,where;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	littelR=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==littelR)
    	{
    		where=(n*m)-i+1;break;
    	}
	}
	int lie=where/n,hang=where%n;                          
	if(hang>0)lie+=1;
	if(hang==0)hang=n;
	if(lie%2==0)hang=(n-hang)+1;
	cout<<lie<<" "<<hang;
	return 0;
}
