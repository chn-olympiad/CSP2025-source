#include<bits/stdc++.h>
//做了三个点没做出来
using namespace std;
struct node{
	int id,w;
}a[100010],b[10001],c[10001];

bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
	
	
		cin>>n;
		int onee=1;
		for(int i=1;i<=n;i++){
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
			cin>>a[i].w>>b[i].w>>c[i].w;
			if((a[i].w==0 && b[i].w==0)||(a[i].w==0 && c[i].w==0)||(c[i].w==0 && b[i].w==0))onee=1;
			else onee=0;
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		int sum=0;
		if(onee)
		{
			sort(a+1,a+n+1,cmp);
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
		
		
			for(int i=n;i>n/2;i--)
			{
				sum+=max(a[i].w,max(b[i].w,c[i].w));
				
			}
		}
		else
		{
			int dp[2000]={0};
		for(int i=1;i<=n;i++)
		{
			
				dp[i]=dp[i-1]+max(a[i].w,max(b[i].w,c[i].w));
				
			
		}
		sum=dp[n];
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}
