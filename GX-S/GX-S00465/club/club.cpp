#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100010;
int T;
int n,a[N][4],t[4],ans;
struct dd
{
	int id,num;
	}e[N];
bool cmp(dd x,dd y)
{
	if(x.id!=y.id)
	    return x.id<y.id;
	return x.num<y.num;
	}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		memset(e,0,sizeof(e));
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			int tsg=1,second=0;
		    for(int j=1; j<=3; j++)
		    {
				cin>>a[i][j];
				if(j!=1 && a[i][j]>=a[i][tsg])
				    tsg=j;
				}
		    for(int j=1; j<=3; j++)
		        if( (j!=tsg && second!=0 && a[i][second]<a[i][j]) || (j!=tsg && second==0) )
		            second=j;
		    t[tsg]++;
		    e[i].id=tsg;
		    e[i].num=a[i][tsg]-a[i][second];
		    ans+=a[i][tsg];
		    }
		sort(e+1,e+n+1,cmp);
		if(t[1]>n/2)
		    for(int i=1; i<=t[1]-n/2; i++)
		        ans-=e[i].num;
		if(t[2]>n/2)
		    for(int i=t[1]+1; i<=t[2]-n/2+t[1]; i++)
		        ans-=e[i].num;
		if(t[3]>n/2)
		    for(int i=t[1]+t[2]+1; i<=t[3]-n/2+t[1]+t[2]; i++)
		        ans-=e[i].num;
		cout<<ans<<endl;
		}
	return 0;
	}
	
