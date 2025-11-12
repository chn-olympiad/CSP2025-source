#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],f[100005],cnt[100005],ans=0,ok=0;
struct node
{
	int t,s,id;
}w[100005];
bool cmp(node x,node y)
{
	return x.s>y.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long sum=0,tmp=0,ans=0,ok=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0&&a[i][3]==0)
			{
				ans++;
			}
			f[i]=0;
			w[++tmp].t=1,w[tmp].s=a[i][1],w[tmp].id=i;
			w[++tmp].t=2,w[tmp].s=a[i][2],w[tmp].id=i;
			w[++tmp].t=3,w[tmp].s=a[i][3],w[tmp].id=i;
		}
		sort(w+1,w+1+tmp,cmp);
		if(ans==n)
		{
			for(int i=1;i<=n/2;i++)
			{
				sum+=w[i].s;
			}
			cout<<sum<<endl;
			ok=1;
		}
		for(int i=1;i<=tmp;i++)
		{
			if(f[w[i].id])
			{
				continue;
			}
			f[w[i].id]=1;
			cnt[w[i].t]++;
			if(cnt[w[i].t]<=n/2)
			{
				sum+=w[i].s;
			}
		}
		if(ok==0)
		{
			cout<<sum<<endl;
		}
	}
	return 0;
}
