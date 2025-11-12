#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],id;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)
		{
			id=i;
			break;
		}
	id=n*m-id+1;
	int c=(id+n-1)/n,r=id%n;
	if(c%2==1)
		r=n-r;
	cout<<c<<" "<<r<<endl;
	return 0;
}
