#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n*m;i++)
	if(a[i]>=a[1])
	ans++;
	int lie=(ans-1)/(2*n)*2+1;
	if((ans-1)%(2*n)>=n)
	lie++;
	int hang;
	if((ans-1)%(2*n)<n)
	hang=(ans-1)%(2*n)+1;
	else
	hang=2*n-(ans-1)%(2*n);
	cout<<lie<<" "<<hang;
	return 0;
}
