#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans;
int x,y,z;
int cha[N],a1[N],a2[N],a3[N],cnt1,cnt2,cnt3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				ans+=x;
				if(y>=z) cha[i]=x-y;
				else cha[i]=x-z;
				a1[++cnt1]=cha[i];
			}
			else if(y>=x&&y>=z)
			{
				ans+=y;
				if(x>=z) cha[i]=y-x;
				else cha[i]=y-z;
				a2[++cnt2]=cha[i];
			}
			else
			{
				ans+=z;
				if(x>=y) cha[i]=z-x;
				else cha[i]=z-y;
				a3[++cnt3]=cha[i];
			}
		}
		if(cnt1>n/2)
		{
			sort(a1+1,a1+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++) ans-=a1[i];
		}
		else if(cnt2>n/2)
		{
			sort(a2+1,a2+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++) ans-=a2[i];
		}
		else if(cnt3>n/2)
		{
			sort(a3+1,a3+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++) ans-=a3[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}