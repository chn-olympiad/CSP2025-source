#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,cnt[4];
struct score
{
	int s[4],mt;
}sc[100005];
bool cmp(score x,score y)
{
	if(max(x.s[(x.mt+1)%3],x.s[(x.mt+2)%3])-x.s[x.mt]!=max(y.s[(y.mt+1)%3],y.s[(y.mt+2)%3])-y.s[y.mt])
		return max(x.s[(x.mt+1)%3],x.s[(x.mt+2)%3])-x.s[x.mt]<max(y.s[(y.mt+1)%3],y.s[(y.mt+2)%3])-y.s[y.mt];
	return min(x.s[(x.mt+1)%3],x.s[(x.mt+2)%3])-x.s[x.mt]<min(y.s[(y.mt+1)%3],y.s[(y.mt+2)%3])-y.s[y.mt];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		int m;
		for(int i=0;i<n;i++)
		{
			cin>>sc[i].s[1]>>sc[i].s[2]>>sc[i].s[3];
			m=max(sc[i].s[1],max(sc[i].s[2],sc[i].s[3]));
			if(m==sc[i].s[1]) sc[i].mt=1;
			if(m==sc[i].s[2]) sc[i].mt=2;
			if(m==sc[i].s[3]) sc[i].mt=3;
		}
		sort(sc,sc+n,cmp);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(cnt[sc[i].mt]*2<n)
			{
				ans+=sc[i].s[sc[i].mt];
				cnt[sc[i].mt]++;
			}
			else if(sc[i].s[(sc[i].mt+1)%3]>sc[i].s[(sc[i].mt+2)%3] && cnt[(sc[i].mt+1)%3]*2<n)
			{
				ans+=sc[i].s[(sc[i].mt+1)%3];
				cnt[(sc[i].mt+1)%3]++;
			}
			else if(sc[i].s[(sc[i].mt+2)%3]>sc[i].s[(sc[i].mt+1)%3] && cnt[(sc[i].mt+2)%3]*2<n)
			{
				ans+=sc[i].s[(sc[i].mt+2)%3];
				cnt[(sc[i].mt+2)%3]++;
			}
			else
			{
				ans+=sc[i].s[(sc[i].mt+1)%3];
				cnt[(sc[i].mt+1)%3]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}