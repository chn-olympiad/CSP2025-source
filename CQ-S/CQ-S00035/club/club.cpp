#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c;
}arr[100001];
int n,t,limi;
int ans,cost1[100001];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		limi=n/2;
		int idx1=0,anum=0,bnum=0,cnum=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			int p=max(arr[i].a,max(arr[i].b,arr[i].c));
			if(p==arr[i].a)anum++,ans+=arr[i].a;
			else if(p==arr[i].b)bnum++,ans+=arr[i].b;
			else cnum++,ans+=arr[i].c;
		}
		if(anum<=limi&&bnum<=limi&&cnum<=limi)
		{
			cout<<ans<<"\n";
			continue;
		}
		if(anum>limi)
		{
			int num=anum-limi;
			for(int i=1;i<=n;i++)
			{
				int p=max(arr[i].a,max(arr[i].b,arr[i].c));
				if(p==arr[i].a)
				{
					cost1[++idx1]=p-max(arr[i].b,arr[i].c);
				}
			}
			sort(cost1+1,cost1+idx1+1);
			for(int i=1;i<=num;i++)ans-=cost1[i];
		}
		else if(bnum>limi)
		{
			int num=bnum-limi;
			for(int i=1;i<=n;i++)
			{
				int p=max(arr[i].a,max(arr[i].b,arr[i].c));
				if(p==arr[i].b&&p!=arr[i].a)
				{
					cost1[++idx1]=p-max(arr[i].a,arr[i].c);
				}
			}
			sort(cost1+1,cost1+idx1+1);
			for(int i=1;i<=num;i++)ans-=cost1[i];
		}
		else
		{
			int num=cnum-limi;
			for(int i=1;i<=n;i++)
			{
				int p=max(arr[i].a,max(arr[i].b,arr[i].c));
				if(p==arr[i].c&&p!=arr[i].b&&p!=arr[i].a)
				{
					cost1[++idx1]=p-max(arr[i].b,arr[i].a);
				}
			}
			sort(cost1+1,cost1+idx1+1);
			for(int i=1;i<=num;i++)ans-=cost1[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
