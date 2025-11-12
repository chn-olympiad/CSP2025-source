#include<bits/stdc++.h>
using namespace std;
int T,n,a[114514][4],cnt[4],qwq,sum,zy[114514],awa;
vector<int> tj;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
while(T--)
{
	cin>>n;
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
		cnt[1]++,zy[i]=1;
		if(a[i][2]>a[i][3]&&a[i][2]>a[i][1])
		cnt[2]++,zy[i]=2;
		if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])
		cnt[3]++,zy[i]=3;
		sum+=max(a[i][1],max(a[i][2],a[i][3]));
	}
		if(cnt[1]>cnt[2]&&cnt[1]>cnt[3])
		qwq=1;
		if(cnt[2]>cnt[3]&&cnt[2]>cnt[1])
		qwq=2;
		if(cnt[3]>cnt[2]&&cnt[3]>cnt[1])
		qwq=3;
		tj.clear();
	for(int i=1;i<=n;i++)
	{
		if(zy[i]==qwq)
		tj.push_back(a[i][qwq]-max(a[i][(qwq)%3+1],a[i][(qwq+1)%3+1]));
	}
	stable_sort(tj.begin(),tj.end());
	awa=0;
	while(cnt[qwq]>n/2)
	{
		sum-=tj[awa];
		awa++;
		cnt[qwq]--;
	}
	cout<<sum<<endl;
}
return 0;
}


