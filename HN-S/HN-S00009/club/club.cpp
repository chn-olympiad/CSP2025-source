#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nd{
	int x,y,z;
}a[100010];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int n1=0,n2=0,n3=0;
		queue<int>q1,q2,q3;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)
			{
				q1.push(i);
				n1++;
				ans+=a[i].x;
			}
			else if(a[i].x<=a[i].y && a[i].y>=a[i].z)
			{
				q2.push(i);
				n2++;
				ans+=a[i].y;
			}
			else if(a[i].z>=a[i].y && a[i].x<=a[i].z)
			{
				q3.push(i);
				n3++;
				ans+=a[i].z;
			}
		}
		int cha[100010];
		int idx=0;
		if(n1>n/2)
		{
			for(int i=1;i<=n1;i++)
			{
				int k=q1.front();
				q1.pop();
				cha[++idx]=max(a[k].y,a[k].z)-a[k].x;
			}
		}
		if(n2>n/2)
		{
			for(int i=1;i<=n2;i++)
			{
				int k=q2.front();
				q2.pop();
				cha[++idx]=max(a[k].x,a[k].z)-a[k].y;
			}
		}
		if(n3>n/2)
		{
			for(int i=1;i<=n3;i++)
			{
				int k=q3.front();
				q3.pop();
				cha[++idx]=max(a[k].y,a[k].x)-a[k].z;
			}
		}
		sort(cha+1,cha+idx+1,greater<int>());
		//for(int i=1;i<=idx;i++)
		//{
		//	cout<<cha[i]<<" ";
		//}
		//cout<<endl;
		for(int i=1;i<=idx-n/2;i++)
		{
			ans+=cha[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
