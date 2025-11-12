#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int x[N],y[N],z[N],xuan[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		int cnt1=0,cnt2=0,cnt3=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>z[i];
			int a=x[i],b=y[i],c=z[i],mx=max(a,max(b,c));
			ans+=mx;
			if(mx==a)
			{
				cnt1++;
			}
			else if(mx==b)
			{
				cnt2++;
			}
			else
			{
				cnt3++;
			}
		}
		int duo=-1;
		if(cnt1>n/2)duo=cnt1;
		if(cnt2>n/2)duo=cnt2;
		if(cnt3>n/2)duo=cnt3;
		if(duo==-1)
		{
			cout<<ans<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int a=x[i],b=y[i],c=z[i];
			int mx=max(max(a,b),c);
			if(mx==a)
			{
				if(duo==cnt1)xuan[++cnt]=a-max(b,c);
			}
			else if(mx==b)
			{
				if(duo==cnt2)xuan[++cnt]=b-max(a,c);
			}
			else
			{
				if(duo==cnt3)xuan[++cnt]=c-max(a,b);
			}
		}
		sort(xuan+1,xuan+cnt+1);
		int i=1;
		while(duo>n/2)
		{
			ans-=xuan[i];
			i++;
			duo--;
		}
		cout<<ans<<endl;
	}
	return 0;
}