#include<bits/stdc++.h>
using namespace std;
#define N 100000
int n;
struct node
{
	int a1,a2,a3;
	int id1,id2,id3;
	int t1,t2;
	bool operator<(const node &t)const
	{
		return t1>t.t1||(t1==t.t1&&t2>t.t2);
	}
}e[N+5];
int cnt[3];
int A0,A1,A2;
inline int read()
{
	int res=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')res=res*10+(x-'0'),x=getchar();
	return res;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			A0=read(),A1=read(),A2=read();
			if(A0>=A1&&A0>=A2&&A1>=A2)e[i]={A0,A1,A2,0,1,2};
			else if(A0>=A1&&A0>=A2&&A2>=A1)e[i]={A0,A2,A1,0,2,1};
			else if(A1>=A0&&A1>=A2&&A0>=A2)e[i]={A1,A0,A2,1,0,2};
			else if(A1>=A0&&A1>=A2&&A2>=A0)e[i]={A1,A2,A0,1,2,0};
			else if(A2>=A1&&A2>=A0&&A0>=A1)e[i]={A2,A0,A1,2,0,1};
			else if(A2>=A1&&A2>=A0&&A1>=A0)e[i]={A2,A1,A0,2,1,0};
			e[i].t1=e[i].a1-e[i].a2,e[i].t2=e[i].a2-e[i].a3;
		}
		sort(e+1,e+n+1);
		int ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[e[i].id1]<n/2)
			{
				ans+=e[i].a1;
				cnt[e[i].id1]++;
			}
			else if(cnt[e[i].id2]<n/2)
			{
				ans+=e[i].a2;
				cnt[e[i].id2]++;
			}
			else
			{
				ans+=e[i].a3;
				cnt[e[i].id3]++;
			}
		}
		printf("%d\n",ans);
	}
}
