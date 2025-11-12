#include<bits/stdc++.h>
using namespace std;
struct area
{
	int begin,end;
}q[550000];
int cnt;
int n,k;
int a[550000];
int s[550000];
long long ans;
bool cmp(area x,area y)
{
	if (x.end==y.end)
		return x.begin<y.begin;
	return x.end<y.end;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	s[1]=a[1];
	if (a[1]==k)
		q[++cnt]={1,1};
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if (a[i]==k)
			q[++cnt]={i,i};
	}	
	for (int i=2;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int now=s[j]^s[j-i];
			if (now==k)
				q[++cnt]={j-i+1,j};
		}
	} 
	sort(q+1,q+cnt+1,cmp);
	/*for (int i=1;i<=cnt;i++)
		cout<<q[i].begin<<' '<<q[i].end<<'\n';*/
	if (cnt==0)
	{
		printf("0");
		return 0; 
	}
	int last=q[1].end;
	ans=1;
	for (int i=2;i<=cnt;i++)
	{
		if (q[i].begin<=last)
			continue;
		last=q[i].end;
		ans++;
	}
	printf("%lld",ans);
	return 0;
} 
/*
9:48 Finish: Maybe 60pts 1~12
10:45 Check: Wtf? 2e5? 
11:00 Oh,no! CCF,where's your parents? 
*/
