#include<iostream>
#include<algorithm>
using namespace std;
long long t,n,sa,sx,sc,ans;
struct intt{
	long long a,b,c,chs,mx;
}ps[100005];
bool cmp(intt x,intt y)
{
	return x.mx<y.mx;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;sa=sx=sc=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&ps[i].a,&ps[i].b,&ps[i].c);
			
			if(ps[i].a>=ps[i].b&&ps[i].a>=ps[i].c)sa++,ans+=ps[i].a,ps[i].mx=min(ps[i].a-ps[i].b,ps[i].a-ps[i].c),ps[i].chs=1;
			else if(ps[i].b>=ps[i].a&&ps[i].b>=ps[i].c)sx++,ans+=ps[i].b,ps[i].mx=min(ps[i].b-ps[i].a,ps[i].b-ps[i].c),ps[i].chs=2;
			else sc++,ans+=ps[i].c,ps[i].mx=min(ps[i].c-ps[i].b,ps[i].c-ps[i].a),ps[i].chs=3;
		}
		int nc2=n/2,mxs=max(sa,max(sx,sc));
		if(mxs>nc2)
		{
			sort(ps+1,ps+n+1,cmp);int bs=0;
			if(sa>nc2)bs=1;if(sx>nc2)bs=2;if(sc>nc2)bs=3;
			
			for(int i=1,cnt=1;cnt<=mxs-nc2;i++)
			if(ps[i].chs==bs)ans-=ps[i].mx,cnt++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

