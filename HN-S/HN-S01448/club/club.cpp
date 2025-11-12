#include<bits/stdc++.h>
using namespace std;
int T,n,ans,t[100005],cnt[5];
struct node
{
	int id,x,op;
}a[300005];

bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			t[i]=0;
			cin>>a[i*3-2].x>>a[i*3-1].x>>a[i*3].x;
			a[i*3-2].id=a[i*3-1].id=a[i*3].id=i;
			a[i*3-2].op=1;
			a[i*3-1].op=2;
			a[i*3].op=3;
		}
		sort(a+1,a+1+n*3,cmp);
		for(int i=1;i<=n*3;i++)
		if(!t[a[i].id]&&cnt[a[i].op]<n/2)
		{
			cnt[a[i].op]++;
			t[a[i].id]=1;
			ans+=a[i].x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
