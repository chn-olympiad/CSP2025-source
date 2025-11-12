#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;

struct NODE
{
	int fi,se,th,t,maxn=0;
	bool wasChose=0;
}stu[N];
long long ans=0;

bool cmp(NODE a,NODE b)
{
	return a.maxn>b.maxn;
}

bool cmp1(NODE a,NODE b)
{
	return a.fi>b.fi;
}

bool cmp2(NODE a,NODE b)
{
	if(a.t==1&&b.t==1)
	{
		if(a.fi==b.fi)return a.se>b.se;
		else return a.fi>b.fi;
	}
	if(a.t==2&&b.t==2)
	{
		if(a.se==b.se)return a.fi>b.fi;
		else return a.se>b.se;
	}
	return a.t>b.t;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i].fi>>stu[i].se>>stu[i].th;
			stu[i].maxn=max(stu[i].maxn,max(stu[i].fi,max(stu[i].se,stu[i].th)));
		}
		
		
		if(n<=30)
		{
			int cnt[4]={};
			for(int i=1;i<=n;i++)
			{
				if(stu[i].fi>stu[i].se&&stu[i].fi>stu[i].th)stu[i].t=1;
				if(stu[i].se>stu[i].fi&&stu[i].se>stu[i].th)stu[i].t=2;
				if(stu[i].th>stu[i].fi&&stu[i].th>stu[i].se)stu[i].t=3;
			}
			sort(stu+1,stu+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				if(stu[i].t==1)
				{
					if(cnt[1]+1<=n/2)
					{
						ans+=stu[i].fi;
						cnt[1]++;
					}else{
						if(stu[i].se>stu[i].th)
						{
							ans+=stu[i].se;
							cnt[2]++;
						}else{
							ans+=stu[i].th;
							cnt[3]++;
						}
					}
				}
				if(stu[i].t==2)
				{
					if(cnt[2]+1<=n/2)
					{
						ans+=stu[i].se;
						cnt[2]++;
					}else{
						if(stu[i].fi>stu[i].th)
						{
							ans+=stu[i].fi;
							cnt[1]++;
						}else{
							ans+=stu[i].th;
							cnt[3]++;
						}
					}
				}
				if(stu[i].t==3)
				{
					if(cnt[3]+1<=n/2)
					{
						ans+=stu[i].th;
						cnt[3]++;
					}else{
						if(stu[i].fi>stu[i].se)
						{
							ans+=stu[i].fi;
							cnt[1]++;
						}else{
							ans+=stu[i].se;
							cnt[2]++;
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
		
		if(stu[1].se==0&&stu[1].th==0&&stu[2].se==0&&stu[2].th==0)
		{
			int cnt=0;
			sort(stu+1,stu+1+n,cmp1);
			for(int i=1;i<=n;i++)
			{
				if(cnt+1<=n/2)
				{
					ans+=stu[i].fi;
					cnt++;
				}else break;
			}
			cout<<ans<<endl;
			continue;
		}
		
		if(stu[1].th==0&&stu[2].th==0&&stu[3].th==0)
		{
			int cntt1=0,cntt2=0,cnt1=0,cnt2=0,pot=0;
			for(int i=1;i<=n;i++)
			{
				if(stu[i].fi>stu[i].se)
				{
					stu[i].t=1;
					cntt1++;
				}
				else{
					stu[i].t=2;
					cntt2++;
				}
			}
			sort(stu+1,stu+1+n,cmp2);
			for(int i=1;i<=cntt1;i++)
			{
				if(cnt1+1<=n/2)
				{
					ans+=stu[i].fi;
					cnt1++;
				}else{
					pot=i;
					break;
				}
			}
			for(int i=pot;i<=n;i++)
			{
				if(cnt2+1<n/2)
				{
					ans+=stu[i].se;
					cnt2++;
				}else{
					break;
				}
				
			}
			cout<<ans<<endl;
			continue;
		}
	}
}
