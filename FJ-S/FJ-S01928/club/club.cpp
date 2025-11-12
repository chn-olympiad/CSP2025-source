#include <bits/stdc++.h>
#define z 787891
using namespace std;
int t,n;
struct node
{
	int a,b,c;
}arr[z];
bool cmp(node a1,node b1)
{
	return a1.a>b1.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;	
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			ans+=arr[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
