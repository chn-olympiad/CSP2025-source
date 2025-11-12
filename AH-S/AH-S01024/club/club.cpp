#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool cmp(int a,int b)
{
	if(a<b)
		return false;
	else
		return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int xxx;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>xxx>>xxx;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
}
