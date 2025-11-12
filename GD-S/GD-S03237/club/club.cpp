#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
struct qwq
{
	int a[4],maxx,mixx,mann;
}awa[100001];
bool cmp1(qwq x,qwq y)
{
	if(x.a[x.maxx]==y.a[y.maxx]) return x.a[x.mixx]>y.a[y.mixx];
	return x.a[x.maxx]>y.a[y.maxx];
}
bool cmp2(qwq x,qwq y)
{
	return x.mann<y.mann;
}
int t,n,cnt[4];
long long sum=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>awa[i].a[1]>>awa[i].a[2]>>awa[i].a[3];
			if(awa[i].a[1]>=awa[i].a[2]&&awa[i].a[1]>=awa[i].a[3])
			{
				awa[i].maxx=1;
				if(awa[i].a[2]>awa[i].a[3])
				{
					awa[i].mixx=2;
					awa[i].mann=awa[i].a[1]-awa[i].a[2];
				}
				else
				{
					awa[i].mixx=3;
					awa[i].mann=awa[i].a[1]-awa[i].a[3];
				}
			}
			else if(awa[i].a[2]>=awa[i].a[1]&&awa[i].a[2]>=awa[i].a[3])
			{
				awa[i].maxx=2;
				if(awa[i].a[1]>awa[i].a[3])
				{
					awa[i].mixx=1;
					awa[i].mann=awa[i].a[2]-awa[i].a[1];
				}
				else
				{
					awa[i].mixx=3;
					awa[i].mann=awa[i].a[2]-awa[i].a[3];
				}
			}
			else if(awa[i].a[3]>=awa[i].a[1]&&awa[i].a[3]>=awa[i].a[2])
			{
				awa[i].maxx=3;
				if(awa[i].a[1]>awa[i].a[2])
				{
					awa[i].mixx=1;
					awa[i].mann=awa[i].a[3]-awa[i].a[1];
				}
				else
				{
					awa[i].mixx=2;
					awa[i].mann=awa[i].a[3]-awa[i].a[2];
				}
			}
			//cout<<awa[i].maxx<<" "<<awa[i].mixx<<endl;
		}
		sort(awa+1,awa+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			cnt[awa[i].maxx]++;
			sum+=awa[i].a[awa[i].maxx];
		}
		int pos=0;
		if(cnt[1]>n/2) pos=1;
		if(cnt[2]>n/2) pos=2;
		if(cnt[3]>n/2) pos=3;
		if(pos==0)
		{
			cout<<sum<<endl;
			continue;
		}
		sort(awa+1,awa+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(awa[i].maxx==pos&&cnt[pos]>n/2)
			{
				cnt[pos]--;
				cnt[awa[i].mixx]++;
				sum-=awa[i].mann;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
