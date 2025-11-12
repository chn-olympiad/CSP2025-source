#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rm,x,y;
	cin>>n>>m;
	vector<int>a(n*m+5);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int rs=a[1];
	sort(a.begin()+1,a.begin()+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
		if(a[i]==rs)
			rm=i;
	if((rm-1)/n%2)
	{
		x=(n-rm%n+1)%n;
		if(x==0)
			x=n;
		y=(rm-1)/n+1;
	}
	else
	{
		x=rm%n;
		if(x==0)
			x=n;
		y=(rm-1)/n+1;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}
