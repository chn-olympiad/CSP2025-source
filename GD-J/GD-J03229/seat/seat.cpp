#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,m,a[110],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(r==a[i])
		{
			r=i;
			break;
		}
	}
	int lei,hang;
	lei=(r-1)/n+1;
	if(lei%2==0)
	{
		hang=n-(r%n)+1;
	}
	else
	{
		if(r==n)
			hang=n;
		else
			hang=r%n;
	}
	cout<<lei<<" "<<hang;
	return 0;
}
