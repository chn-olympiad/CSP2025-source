#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
struct MoonHalo
{
	int a,b,c,d,d2,e,e2;
}a[maxn];
struct Rubia
{
	int x,y;
	friend bool operator<(Rubia a,Rubia b)
	{
		return a.x>b.x;
	}
};
bool cmp(MoonHalo x,MoonHalo y)
{
	return x.d2-x.e2>y.d2-y.e2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,n;
	cin>>T;
	while(T--)
	{
		priority_queue<Rubia> pq1,pq2,pq3;
		vector<int> v1,v2,v3;
		int s1=0,s2=0,s3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				a[i].d=1,a[i].d2=a[i].a;
				if(max(a[i].b,a[i].c)==a[i].b) a[i].e=2,a[i].e2=a[i].b;
				else a[i].e=3,a[i].e2=a[i].c;
			} 
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				a[i].d=2,a[i].d2=a[i].b;
				if(max(a[i].a,a[i].c)==a[i].a) a[i].e=1,a[i].e2=a[i].a;
				else a[i].e=3,a[i].e2=a[i].c;
			} 
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b)
			{
				a[i].d=3,a[i].d2=a[i].c;
				if(max(a[i].a,a[i].b)==a[i].a) a[i].e=1,a[i].e2=a[i].a;
				else a[i].e=2,a[i].e2=a[i].b;
			} 
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].d==1&&s1<n/2) ans+=a[i].a,s1++,pq1.push({a[i].a,i});
			else if(a[i].d==1&&s1>=n/2)
			{
				int tmp=ans,ts1=s1,ts2=s2,ts3=s3,flag,x,xx;
				if(!pq1.empty())
				{
					int j=pq1.top().y,t=pq1.top().x;
					if(a[j].e==2&&a[j].b+a[i].a>t)
					{
						if(ts2<n/2)
						{
							pq1.pop();
							ans-=t;
							flag=1,x=a[j].b,xx=j;
							ans+=a[i].a+a[j].b,ts2++;
						}
						else if(ts2>=n/2)
						{
							if(a[j].c+a[i].a>t)
							{
								pq1.pop();
								ans-=t;
								flag=2,x=a[j].c,xx=j;
								
								ans+=a[i].a+a[j].c,ts3++;
							}
						}
					} 
					else if(a[j].e==3&&a[j].c+a[i].a>t)
					{
						if(ts3<n/2)
						{
							pq1.pop();
							ans-=t;
							flag=3,x=a[j].c,xx=j;
							
							ans+=a[i].a+a[j].c,ts3++;
						}
						else if(ts3>=n/2)
						{
							if(a[j].b+a[i].a>t)
							{
								pq1.pop();
								ans-=t;
								flag=4,x=a[j].b,xx=j;
								ans+=a[i].a+a[j].b,ts2++;
							}
						}
					} 
				}
				int x1;
				if(a[i].e==2&&s2<n/2) tmp+=a[i].b,s2++,x1=2;
				else if(a[i].e==2&&s2>=n/2) tmp+=a[i].c,s3++,x1=3; 
				else if(a[i].e==3&&s3<n/2) tmp+=a[i].c,s3++,x1=3;
				else if(a[i].e==3&&s3>=n/2) tmp+=a[i].b,s2++,x1=2;
				if(tmp>ans)
				{
					ans=tmp;
					if(x1==2) pq2.push({a[i].b,i});
					else pq3.push({a[i].c,i});
				}
				else
				{
					s1=ts1,s2=ts2,s3=ts3; 
					if(flag==1) pq1.push({a[i].a,i}),pq2.push({x,xx});
					if(flag==2) pq1.push({a[i].a,i}),pq3.push({x,xx});
					if(flag==3) pq1.push({a[i].a,i}),pq3.push({x,xx});
					if(flag==4) pq1.push({a[i].a,i}),pq2.push({x,xx});
				} 
			}
			else if(a[i].d==2&&s2<n/2) ans+=a[i].b,s2++,pq2.push({a[i].b,i});
			else if(a[i].d==2&&s2>=n/2)
			{
				int tmp=ans,ts1=s1,ts2=s2,ts3=s3,flag,x,xx;
				if(!pq2.empty())
				{
					int j=pq2.top().y,t=pq2.top().x;
					if(a[j].e==1&&a[j].a+a[i].b>t)
					{
						if(ts1<n/2)
						{
							pq2.pop();
							ans-=t;
							flag=1,x=a[j].a,xx=j;
							
							ans+=a[i].b+a[j].a,ts1++;
						}
						else if(ts1>=n/2)
						{
							if(a[j].c+a[i].a>t)
							{
								pq2.pop();
								flag=2;
								ans-=t,x=a[j].c,xx=j;
								
								ans+=a[i].b+a[j].c,ts3++;
							}
						}
					} 
					else if(a[j].e==3&&a[j].c+a[i].a>t)
					{
						if(ts3<n/2)
						{
							pq2.pop();
							ans-=t,x=a[j].c;
							flag=3,xx=j;
							ans+=a[i].b+a[j].c,ts3++;
						}
						else if(ts3>=n/2)
						{
							if(a[j].a+a[i].b>t)
							{
								pq2.pop();
								ans-=t,x=a[j].a;
								flag=4,xx=j;
								ans+=a[i].b+a[j].a,ts2++;
							}
						}
					} 
				}
				int x1;
				if(a[i].e==1&&s1<n/2) tmp+=a[i].a,s1++,x1=1;
				else if(a[i].e==1&&s1>=n/2) tmp+=a[i].c,s3++,x1=3; 
				else if(a[i].e==3&&s3<n/2) tmp+=a[i].c,s3++,x1=3;
				else if(a[i].e==3&&s3>=n/2) tmp+=a[i].a,s1++,x1=1;
				if(tmp>ans)
				{
					ans=tmp;
					if(x1==1) pq1.push({a[i].a,i});
					else pq3.push({a[i].c,i});
				} 
				else
				{
					s1=ts1,s2=ts2,s3=ts3; 
					if(flag==1) pq2.push({a[i].b,i}),pq1.push({x,xx});
					if(flag==2) pq2.push({a[i].b,i}),pq3.push({x,xx});
					if(flag==3) pq2.push({a[i].b,i}),pq3.push({x,xx});
					if(flag==4) pq2.push({a[i].b,i}),pq1.push({x,xx});
				} 
			}
			else if(a[i].d==3&&s3<n/2) ans+=a[i].c,s3++,pq3.push({a[i].c,i});
			else if(a[i].d==3&&s3>=n/2)
			{
				int tmp=ans,ts1=s1,ts2=s2,ts3=s3,flag,x,xx;
				if(!pq3.empty())
				{
					int j=pq3.top().y,t=pq3.top().x;
					if(a[j].e==1&&a[j].a+a[i].c>t)
					{
						if(ts1<n/2)
						{
							pq3.pop();
							ans-=t;
							flag=1,x=a[j].a,xx=j;
							
							ans+=a[i].c+a[j].a,ts1++;
						}
						else if(ts1>=n/2)
						{
							if(a[j].b+a[i].a>t)
							{
								pq3.pop();
								ans-=t;
								flag=2,x=a[j].b,xx=j;
								
								ans+=a[i].c+a[j].b,ts2++;
							}
						}
					} 
					else if(a[j].e==2&&a[j].b+a[i].c>t)
					{
						if(ts2<n/2)
						{
							pq3.pop();
							ans-=t;
							flag=3,x=a[j].b,xx=j;
							
							ans+=a[i].c+a[j].b,ts2++;
						}
						else if(ts2>=n/2)
						{
							if(a[j].a+a[i].c>t)
							{
								pq3.pop();
								ans-=t;
								flag=4,x=a[j].a,xx=j;
								
								ans+=a[i].c+a[j].a,ts1++;
							}
						}
					} 
				}
				int x1;
				if(a[i].e==1&&s1<n/2) tmp+=a[i].a,s1++,x1=1;
				else if(a[i].e==1&&s1>=n/2) tmp+=a[i].b,s2++,x1=2; 
				else if(a[i].e==2&&s2<n/2) tmp+=a[i].b,s2++,x1=2;
				else if(a[i].e==2&&s2>=n/2) tmp+=a[i].a,s1++,x1=1;
				if(tmp>ans)
				{
					ans=tmp;
					if(x1==1) pq1.push({a[i].a,i});
					else pq2.push({a[i].b,i});
				} 
				else
				{
					s1=ts1,s2=ts2,s3=ts3; 
					if(flag==1) pq3.push({a[i].c,i}),pq1.push({x,xx});
					if(flag==2) pq3.push({a[i].c,i}),pq2.push({x,xx});
					if(flag==3) pq3.push({a[i].c,i}),pq2.push({x,xx});
					if(flag==4) pq3.push({a[i].c,i}),pq1.push({x,xx});
				}
			}
		//cout<<ans<<' ';
		}
	//	while(!pq1.empty()) cout<<pq1.top().x<<' ',pq1.pop();cout<<'\n';
	//	while(!pq2.empty()) cout<<pq2.top().x<<' ',pq2.pop();cout<<'\n';
	//	while(!pq3.empty()) cout<<pq3.top().x<<' ',pq3.pop();cout<<'\n';

		
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
4
1 3 5
2 3 6
5 5 8
0 2 0

1
10
2020 14533 18961!!!
2423 15344 16322!!!
1910 6224 16178
2038 9963 19722!!!
8375 10557 5444
3518 14615 17976!!!
6188 13424 16615!!!
8769 509 4394
958 3195 9953
16441 5313 10926! 

*/
