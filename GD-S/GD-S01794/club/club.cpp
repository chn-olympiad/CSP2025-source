#include <bits/stdc++.h>
using namespace std;
int t;
long long n,ans;
struct cheng{
	long long a1,a2,a3; 
}ren[100500];
bool cmp1(cheng a,cheng b)
{
	return a.a1>b.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>ren[j].a1>>ren[j].a2>>ren[j].a3;
		} 
		if(n==2)
		{
			long long p=max(ren[1].a1+ren[2].a2,ren[1].a1+ren[2].a3);
			long long q=max(ren[1].a2+ren[2].a1,ren[1].a2+ren[2].a3);
			long long o=max(ren[1].a3+ren[2].a2,ren[1].a3+ren[2].a1);
			cout<<max(max(p,q),o)<<endl;
		 } 
		else
		{
		sort(ren+1,ren+1+n,cmp1);
		for(int j=1;j<=n/2;j++)
		{
			ans+=ren[j].a1;
		}
		cout<<ans<<endl;
		}
	}
	return 0;
}
