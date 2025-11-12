#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100005],b[100005],c[100005];
	cin>>t;
	while(t)
	{
		cin>>n;
		fill(a+1,a+100006,0);
		fill(b+1,b+100006,0);
		fill(c+1,c+100006,0);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		int d=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n/2;i++)
		{
			d+=a[n+1-i];
		}
		cout<<d<<endl;
		t--;
	}
	return 0;
}