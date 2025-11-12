#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,s=n*m,ss=1;
	cin>>x;
	for(int i=2;i<=s;i++)
	{
		int a;
		cin>>a;
		if(a>x)
			ss++;
	}
	int l=ss/n+(ss%n!=0),h=ss%n+(ss%n==0)*n;
	if(l%2==0)
		h=n-h+1;
	cout<<l<<' '<<h<<"\n";
	return 0;
}
