#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N]; 
int pos;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[++pos];
			a[pos]*=-1;
		}
	}
	int h=a[1];
	int ans;
	sort(a+1,a+pos+1);
	for(int i=1;i<=pos;i++)
	{
		if(a[i]==h) ans=i;
	}
	int l=(ans+n-1)/n;
	cout<<l<<" "<<(l%2==1?(ans-1)%n+1:n-(ans-1)%n);
	return 0;
}
