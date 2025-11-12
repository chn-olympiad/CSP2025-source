#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[3],stk[200001],tp;
int op;
struct STUD
{
	int a,b,c;
}stu[200001];
int fnxt(int i,int x)
{
	int ans=0;
	if(stu[i].a<=x&&op!=0) ans=max(ans,stu[i].a);
	if(stu[i].b<=x&&op!=1) ans=max(ans,stu[i].b);
	if(stu[i].c<=x&&op!=2) ans=max(ans,stu[i].c);
	return ans;
}
bool cmp(int xx,int yy)
{
	STUD x=stu[xx],y=stu[yy];
	if(op==0) return x.a-fnxt(xx,x.a)<y.a-fnxt(yy,y.a);
	if(op==1) return x.b-fnxt(xx,x.b)<y.b-fnxt(yy,y.b);
	if(op==2) return x.c-fnxt(xx,x.c)<y.c-fnxt(yy,y.c);
}
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cnt[0]=cnt[1]=cnt[2]=0;
		tp=0;
		cin>>n;
		for(int i=1;i<=n;i++) stu[i].a=stu[i].b=stu[i].c=0;
		for(int i=1;i<=n;i++) stk[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&stu[i].a,&stu[i].b,&stu[i].c);
			if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c) cnt[0]++;
			else if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c) cnt[1]++;
			else if(stu[i].c>=stu[i].b&&stu[i].c>=stu[i].a) cnt[2]++;
		}
		ll ans=0;
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(max(stu[i].a,stu[i].b),stu[i].c);
			}
			cout<<ans<<'\n';
		}
		else
		{
			for(int i=0;i<3;i++) if(cnt[i]>n/2) op=i;
			for(int i=1;i<=n;i++)
			{
				if(stu[i].a>=stu[i].b&&stu[i].a>=stu[i].c&&op==0) stk[++tp]=i;
				else if(stu[i].b>=stu[i].a&&stu[i].b>=stu[i].c&&op==1) stk[++tp]=i;
				else if(stu[i].c>=stu[i].b&&stu[i].c>=stu[i].a&&op==2) stk[++tp]=i;
				ans+=max(max(stu[i].a,stu[i].b),stu[i].c);
			}
			sort(stk+1,stk+tp+1,cmp);
			for(int i=1;i<=tp;i++)
			{
				if(op==0) ans-=stu[stk[i]].a-fnxt(stk[i],stu[stk[i]].a);
				if(op==1) ans-=stu[stk[i]].b-fnxt(stk[i],stu[stk[i]].b);
				if(op==2) ans-=stu[stk[i]].c-fnxt(stk[i],stu[stk[i]].c);
				cnt[op]--;
				if(cnt[op]<=n/2) break;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}