#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,j,n;
	cin>>t;
	for(i=1;i<=t;++i)
	{	
		cin>>n;
		for(j=1;j<=n;++j)
			cin>>a[i]>>b[i]>>c[i];
		sort(a+1,a+n+1);
		for(int s=n;s>=n/2;--s)
			ans+=a[s];
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
