#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define f(n) for(int i=1;i<=n;i++)
bool cmp(ll x,ll y)
{
	return x<y;
}
ll a[100001][3],sm[3],stt,dm[100001],ans;
int num[3],n;
int pd(int id)
{
	if(a[id][0]>=a[id][1]&&a[id][0]>=a[id][2])return 0;
	else if(a[id][1]>=a[id][2])return 1;
	else return 2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		num[0]=0;num[1]=0;num[2]=0;
		sm[0]=0;sm[1]=0;sm[2]=0;stt=0;ans=0;
		f(100000)
		{
			a[i][0]=0;a[i][1]=0;a[i][2]=0;
			dm[i]=0;
		}
		cin>>n;
		f(n)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int ls=pd(i);
			if(ls==0)
			{
				sm[0]+=a[i][0];
				num[0]++;
				dm[i]=a[i][0]-max(a[i][1],a[i][2]);
			}
			else if(ls==1)
			{
				sm[1]+=a[i][1];
				num[1]++;
				dm[i]=a[i][1]-max(a[i][0],a[i][2]);
			}
			else
			{
				sm[2]+=a[i][2];
				num[2]++;
				dm[i]=a[i][2]-max(a[i][0],a[i][1]);
			}
		}
		ans=sm[0]+sm[1]+sm[2];
		if(num[0]<=n/2&&num[1]<=n/2&&num[2]<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		//cout<<"-1\n";
		int rt;
		f(3)if(num[i-1]>n/2)rt=i-1;
		f(n)if(pd(i)==rt)
		{
			stt++;
			dm[stt]=dm[i];
		}
		sort(dm+1,dm+stt+1,cmp);
		f(num[rt]-n/2)ans-=dm[i];
		cout<<ans<<"\n";
	}
	
	return 0;
}


