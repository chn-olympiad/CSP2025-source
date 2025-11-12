#include<bits/stdc++.h>
#define int long long
int t,n;
struct dat{int mem,id,num;}a[114514][3];
dat q1[114514],q2[114514],q3[114514],q[114514];
bool cmp(dat x,dat y){return x.num>y.num;}
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		memset(q3,0,sizeof(q3));
		memset(q,0,sizeof(q));
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][1].num,a[i][1].mem=i,a[i][1].id=1;q1[i]=a[i][1];
			cin>>a[i][2].num,a[i][2].mem=i,a[i][2].id=2;q2[i]=a[i][2];
			cin>>a[i][3].num,a[i][3].mem=i,a[i][3].id=3;q3[i]=a[i][3];
		}
		sort(q1+1,q1+n+1,cmp);
		sort(q2+1,q2+n+1,cmp);
		sort(q3+1,q3+n+1,cmp);
		bool vis[114514]={0};
		int m1=0,m2=0,m3=0,idx=1,ans=0;
		for(int i=1;i<=n/2;i++) q[idx++]=q1[i],q[idx++]=q2[i],q[idx++]=q3[i];
		sort(q+1,q+n/2*3+1,cmp);
		for(int i=1;i<=n/2*3;i++)
		{
			if(!vis[q[i].mem])
			{
				if(q[i].id==1&&m1+1>n/2) continue; 
				if(q[i].id==2&&m2+1>n/2) continue; 
				if(q[i].id==3&&m3+1>n/2) continue;
				ans+=q[i].num,vis[q[i].mem]=1; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//I love CCF
//rp++;
/*
	·¢ÉäÇøÚÀ ¶ÂÇÅÒ»ºÅÎ»
	³éÍêÎ÷´ó ÔÙÈ¥³éÀ¶ºÚ
	µç¾º²ËÊÇÔ­×ï
	ÎÚÂ³Â³~
	µ¼µ¯Ñ²·É ²»ËÍÄãËÍË­
	Â¶ÄÈÐ¡½ã ºÃÏñÔÚÀ¶Ð±
	¸¡Ä¾ÔÚÌìÉÏ·É
*/ 
