#include<iostream>
#include<algorithm>
using namespace std;
int a[105],n,m,r,rpot,hang,lie;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			rpot=i;
			break;
		}
	}
//	cout<<rpot<<"\n";
	if(rpot%n!=0)lie=rpot/n+1;
	else lie=rpot/n;
	if(lie%2==0)
	{
		if(rpot%n==0)hang=1;
		else hang=n-(rpot%n)+1;
	} 
	else if(rpot%n==0)hang=n;
	else hang=rpot%n;
	cout<<lie<<" "<<hang;
	return 0;
}
