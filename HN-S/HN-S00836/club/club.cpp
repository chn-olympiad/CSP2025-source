#include<bits/stdc++.h>//25
using namespace std;
int t=0,n=0,ans=0,c1=0,c2=0,c3=0;
int a[100010][5]={0};
int b[100010]={0};
void f(int st,int sum)
{
	if(st>n)
	{
		ans=max(ans,sum);return;
	}
	if(c1<n/2)
	{
		c1++;f(st+1,sum+a[st][1]);c1--;
	}
	if(c2<n/2)
	{
		c2++;f(st+1,sum+a[st][2]);c2--;
	}
	if(c3<n/2)
	{
		c3++;f(st+1,sum+a[st][3]);c3--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=c1=c2=c3=0;
		cin>>n;
		int f2=0,f3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];if(a[i][2]!=0)f2=1; if(a[i][3]!=0)f3=1;
		}
		if(!f2&&!f3)
		{
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n;i>=n-n/2;i--)ans+=b[i];
			cout<<ans<<"\n";continue;
		}
		f(1,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
