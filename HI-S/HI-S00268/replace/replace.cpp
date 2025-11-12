#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
#define ll long long
ll n,bz,k,ans,key,q,x,y,lll,rr;
string s[maxn][2],t1,t2;
struct sj
{
	int cj,qs,zd;
}a1[maxn];
bool cmp(sj x,sj y)
{
	x.cj<y.cj;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		x=s[i][0].find('b');
		y=s[i][1].find('b');
		a1[i].cj=x-y;a1[i].qs=x;a1[i].zd=s[i][0].size();
	}
	sort(a1+1,a1+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>t1>>t2;
		x=t1.find('b');
		y=t2.find('b');
		key=x-y;
		int l1=1,r1=n,mid1;
		while(l1<=r1)
		{
			mid1=(l1+r1)/2;
			if(a1[mid1].cj>=key)
			{
				r1=mid1-1;
			}
			else
			{
				l1=mid1+1;
			}
		}
		lll=l1;
		int l2=1,r2=n,mid2;
		while(l2<=r2)
		{
			mid2=(l2+r2)/2;
			if(a1[mid2].cj>key)
			{
				r2=mid2-1;
			}
			else
			{
				l2=mid2+1;
			}
		}
		rr=r2;
		for(int j=lll;j<=rr;j++)
		{
			if(a1[j].qs<=x&&a1[j].zd-a1[j].qs<=t1.size()-x)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
