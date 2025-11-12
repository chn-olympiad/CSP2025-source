#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long ans=0;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		cin>>n;
		ans=0;
		for(int i=1,e;i<=n;i++){
			scanf("%d%d%d",&a[i],&e,&e);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
}
