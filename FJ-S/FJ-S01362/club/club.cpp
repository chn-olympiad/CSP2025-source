#include<bits/stdc++.h>
using namespace std;
const int LL=1e5+7;
struct node
{
	long long sum;
	int idx;
};
node a[LL][3];
vector<int>f[3];
long long s[LL];
int T,N;
bool cmp(node x,node y)
{
	return x.sum>y.sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		long long Ans=0;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			scanf("%lld %lld %lld",&a[i][0].sum,&a[i][1].sum,&a[i][2].sum);
			a[i][0].idx=0,a[i][1].idx=1,a[i][2].idx=2;
			sort(a[i],a[i]+3,cmp);
			f[a[i][0].idx].push_back(i);
		}
		int a1=f[0].size(),a2=f[1].size(),a3=f[2].size();
		int tmp[3]={a1,a2,a3},x;
		sort(tmp,tmp+3);
		for(int i=0;i<3;i++)
		{
			if(f[i].size()==tmp[2])
				x=i;
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<f[i].size();j++)
				Ans+=a[f[i][j]][0].sum;
		if(tmp[2]>N/2)
		{
			for(int i=0;i<f[x].size();i++)
				s[i]=a[f[x][i]][0].sum-a[f[x][i]][1].sum;
			sort(s,s+tmp[2]);
			for(int i=0;i<tmp[2]-N/2;i++)
				Ans-=s[i];
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
