#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,z,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++)
	{
		cin>>a[i];
		if(i==1) t=a[i];
	}
	sort(a+1,a+1+h);
	for(int i=h;i>=1;i--)
	{
		l++;
		if(t==a[i]) z=l;
	}
	l=0;t=0;
	t=z;
	while(t>n)
	{
		t-=n;
		l++;
	}
	if(t>0) l++;
	cout<<l;
	if(l%2==0) cout<<" "<<n-t+1;
	else cout<<" "<<t;
	fclose(stdin);
	fclose(stdout);
return 0;
}
