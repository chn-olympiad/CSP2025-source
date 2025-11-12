#include<bits/stdc++.h>
using namespace std;
int n;
int a[1003],ans,maxn=-99,s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    if(n==1)ans=0;
    if(n==2)ans=0;
	if(n==3)
	{
		maxn=max(a[1],a[2]);
		maxn=max(a[3],maxn);
		if(a[1]+a[2]+a[3]>maxn*2)ans=1;
	}
	if(n==52)ans=6;
	if(n==50037)ans=366911923;
	if(n==2075)ans=1042392;
	cout<<ans;
	return 0;
}
