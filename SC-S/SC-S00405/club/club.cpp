#include<cstdio>
#include<algorithm>
using namespace std;
struct pr{
	int id,k;
} p[100001];
bool cmp(pr x, pr y)
{
	return x.k<y.k;
}
int s[100001][4],sc[100001],ft[100001];
//s:数据 sc:第二大的编号 ft:第一大的编号
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long ans=0;
		int k[4]={0};
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&s[i][1],&s[i][2],&s[i][3]);
			if(s[i][1]>=s[i][2])
				ft[i]=1,sc[i]=2;
			else
				ft[i]=2,sc[i]=1;
			if(s[i][3]>=s[i][ft[i]])
				sc[i]=ft[i],ft[i]=3;
			else if(s[i][3]>=s[i][sc[i]])
				sc[i]=3;
			ans+=s[i][ft[i]];
			k[ft[i]]++;
			p[i].id=i;
			p[i].k=s[i][ft[i]]-s[i][sc[i]];
		}
		sort(p+1,p+n+1,cmp);
		int r=0;
		if(k[1]>n/2)
			r=1;
		else if(k[2]>n/2)
			r=2;
		else
			r=3;
		int j=1;
		while(r!=0&&k[r]>n/2)
		{
			k[r]--;
			while(ft[p[j].id]!=r)
				j++;
			ans-=p[j].k;
			j++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//freopen
//T1 club
//Luogu: WOLFSTAR(1044658)
//CSP-S2025 rp++
//NOIP2025 rp++
//来てくれてありがとう！

//刚好1h拿下T1，爽
//可以放心回去打啤酒烧烤了