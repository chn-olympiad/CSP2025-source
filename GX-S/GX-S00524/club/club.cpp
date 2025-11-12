#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200009;
vector<int>pd[4];
int t,n,x,y,z;
int cp[N];
int ans;
int l[4];
int flag=0;
void clear()
{
	memset(l,0,sizeof(l));
	memset(pd,0,sizeof(pd));
	ans=0;
	flag=0;
	
	return;
}

void solve2()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;

		int sum=max(x,y);
		sum=max(sum,z);
		if(sum==x)
		{
			cp[i]=min(x-y,x-z);
			pd[1].push_back(cp[i]);
			l[1]+=1;
			if(l[1]>n/2)
			{
				flag=1;
			}
			cp[i]=min(x-y,x-z);
			ans+=x;
			continue;
		}
		else if(sum==y)
		{
			cp[i]=min(y-x,y-z);
			pd[2].push_back(cp[i]);
			l[2]+=1;
			if(l[2]>n/2)
			{
				flag=2;
			}
			cp[i]=min(y-x,y-z);
			ans+=y;
			continue;
		}
		else
		{
			cp[i]=min(z-x,z-y);
			pd[3].push_back(cp[i]);
			l[3]+=1;
			if(l[3]>n/2)
			{
				flag=3;
			}
			
			cp[i]=min(z-x,z-y);
			ans+=z;
			continue;
		}
	
		
	}
	if(flag==0)
	{
		cout<<ans<<endl;
		return;
	}
	else
	{
		sort(pd[flag].begin(),pd[flag].end());
		int tn=0;
		while(l[flag]>n/2)
		{
			ans-=pd[flag][tn];
			tn+=1;
			l[flag]-=1;
		}
		cout<<ans<<endl;
	}
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		clear();
		solve2();
	}
	return 0;
}
	
