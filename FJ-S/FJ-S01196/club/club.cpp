#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct node
{
	int a,b,c,maxn,maxi,cha;
}s[N];
int n,t,sum[4]={0,0,0,0};
long long ans;
bool cmp(node a1,node b1)
{
	return a1.cha>b1.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int w=1;w<=t;w++)
	{
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].maxn=max(max(s[i].a,s[i].b),s[i].c);
			ans+=s[i].maxn;
			if(s[i].maxn==s[i].a)
			{
				s[i].maxi=1;
				s[i].cha=s[i].a-max(s[i].b,s[i].c);
				continue;
			}
			if(s[i].maxn==s[i].b)
			{
				s[i].maxi=2;
				s[i].cha=s[i].b-max(s[i].a,s[i].c);
				continue;
			}s[i].maxi=3;
			s[i].cha=s[i].c-max(s[i].b,s[i].a);
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(sum[s[i].maxi]>=n/2)
			{
				ans-=s[i].cha;
			}
			else
			{
				sum[s[i].maxi]++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

