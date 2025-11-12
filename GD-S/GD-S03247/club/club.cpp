#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
bool fl;
int n,ans;
struct xyx{
	int a,b,c,mx;
}p[maxn];

bool cmp1(xyx xx,xyx yy)
{
	return xx.a>yy.a;
}

void dfs(int x,int sum,int a1,int b1,int c1)
{
//	cout<<"x:"<<x<<" sum:"<<sum<<" a1:"<<a1<<" b1:"<<b1<<" c1:"<<c1<<'\n';
	if(a1>n/2 || b1>n/2 || c1>n/2) return;
	if(x>=n+1)
	{
//		cout<<111<<ans<<" "<<sum<<'\n';
		ans=max(ans,sum);
		return;
	}
	
	dfs(x+1,sum+p[x].a,a1+1,b1,c1);
	dfs(x+1,sum+p[x].b,a1,b1+1,c1);
	dfs(x+1,sum+p[x].c,a1,b1,c1+1);
	return;
}

int main()
{
	
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,ans2=0;
		memset(p,0,sizeof p);
		fl=0;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>=p[i].b&&p[i].a>=p[i].c) cnt1++,p[i].mx=p[i].a;
			else if(p[i].b>=p[i].a&&p[i].b>=p[i].c) cnt2++,p[i].mx=p[i].b;
			else cnt3++,p[i].mx=p[i].c;
			
			if(p[i].b||p[i].c) fl=1;
			
			ans2+=p[i].mx;
		}
		if(!fl)
		{
			int ans1=0;
			sort(p+1,p+1+n,cmp1);
			for(int i=1;i<=n/2;i++) ans1+=p[i].a;
			cout<<ans1<<'\n';
			continue;
		}
		if(cnt1<=n/2 &&cnt2<=n/2 &&cnt3<=n/2)
		{
			cout<<ans2<<'\n';
			continue;
		}
		
//		cout<<"ans:"<<ans<<'\n';
		
		dfs(0,0,0,0,0);
		
		cout<<ans<<'\n';
		ans=0;
	}
	
	
	
	return 0;
}




