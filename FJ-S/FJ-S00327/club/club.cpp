#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
};
int dp[10001][1][1][1]={0};
bool cmp(club a,club b)
{
	return a.a>b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		club a[10001];
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
		if(n==2)
		{
			int l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l12,l34,l56;
			l1=a[1].a+a[2].b;
			l2=a[1].a+a[2].c;
			
			l3=a[1].b+a[2].a;
			l4=a[1].b+a[2].c;
			
			l4=a[1].c+a[2].a;
			l5=a[1].c+a[2].b;
			
			l12=max(l1,l2);
			l34=max(l3,l4);
			l56=max(l5,l6);
			int ans=max(l12,max(l34,l56));
			cout<<ans<<endl;
		}
		else
		{
			sort(a+1,a+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++)sum+=a[i].a;
			cout<<sum<<endl;
			
		}
	}
	return 0; 
} 
