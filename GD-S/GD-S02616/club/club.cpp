#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int cnt[N],s[5],ma[N],id[N],k[N];
int a[N][5],f[N][5];
priority_queue<int,vector<int>,greater<int>>q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cnt[i]=0;
		s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			k[i]=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)
				f[i][j]=(a[i][j]==k[i]),cnt[i]+=f[i][j];
			if(cnt[i]==1)
			{
				if(f[i][1])id[i]=1,s[1]++,ma[i]=max(a[i][2],a[i][3]);
				if(f[i][2])id[i]=2,s[2]++,ma[i]=max(a[i][1],a[i][3]);
				if(f[i][3])id[i]=3,s[3]++,ma[i]=max(a[i][1],a[i][2]);
			}
			ans+=k[i];
		}
		int chk=max(s[1],max(s[2],s[3]));
		if(chk<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		int num;
		if(s[1]==chk)num=1;
		if(s[2]==chk)num=2;
		if(s[3]==chk)num=3;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]!=1)continue;
			if(num==id[i])q.push(k[i]-ma[i]);
		}
		for(int i=1;i<=chk-n/2;i++)
			ans-=q.top(),q.pop();
		cout<<ans<<endl;
		while(!q.empty())
			q.pop();
	}
	return 0;
}
