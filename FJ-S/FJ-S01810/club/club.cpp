#include<bits/stdc++.h>
#define N 100010
using namespace std;

int n,ans,cnt[3];
struct node
{
	pair<int,int>a[3]; // score rank
}stu[N];

void aha()
{
	ans=cnt[0]=cnt[1]=cnt[2]=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&stu[i].a[0].first,&stu[i].a[1].first,&stu[i].a[2].first);
		
		stu[i].a[0].second=0,stu[i].a[1].second=1,stu[i].a[2].second=2;
		
		sort(stu[i].a,stu[i].a+3,greater<pair<int,int>>());
	}
	
	sort(stu+1,stu+1+n,[&](node X,node Y){
//		if(X.a[0].first==Y.a[0].first) return X.a[1].first<Y.a[1].first;
//		else return X.a[0].first>Y.a[0].first;
		return X.a[1].first-X.a[0].first < Y.a[1].first-Y.a[0].first;
	});
	
	for(int i=1;i<=n;i++)
	{
		if(cnt[stu[i].a[0].second]<n/2)
		{
			cnt[stu[i].a[0].second]++;
			ans+=stu[i].a[0].first;
		}
		else
		{
			cnt[stu[i].a[1].second]++;
			ans+=stu[i].a[1].first;
		}
	}
	
	
	printf("%d\n",ans);
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		aha();
	}
	return 0;
}