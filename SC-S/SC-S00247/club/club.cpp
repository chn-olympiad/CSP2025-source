#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct mem{
	int a,b,c;
}a[N];
bool cmp1(mem a,mem b)
{
	return a.a>b.a;
}
bool A,B;
int t,n,ans;
int mi[30][30][30][1000];
int s(int as,int b,int c,int now)
{
	if(as>n/2)
	{
		return -100;
	}
	if(b>n/2)
	{
		return -100;
	}
	if(c>n/2)
	{
		return -100;
	}
	if(as+b+c==n)
	{
		return now;
	}
	if(as*2==n)
	{
		if(as<30&&b<30&&c<30&&now<1000)
		{
			if(mi[as][b][c][now]==0)
		{
			mi[as][b][c][now]=max(s(as,b+1,c,now+a[as+b+c].b),s(as,b,c+1,now+a[as+b+c].c));
		}
		return mi[as][b][c][now];
		}
		return max(s(as,b+1,c,now+a[as+b+c].b),s(as,b,c+1,now+a[as+b+c].c));
	}
	if(b*2==n)
	{
		if(as<30&&b<30&&c<30&&now<1000)
		{
			if(mi[as][b][c][now]==0)
		{
			mi[as][b][c][now]=max(s(as+1,b,c,now+a[as+b+c].a),s(as,b,c+1,now+a[as+b+c].c));
		}
		return mi[as][b][c][now];
		}
		return max(s(as+1,b,c,now+a[as+b+c].a),s(as,b,c+1,now+a[as+b+c].c));
	}
	if(c*2==n||B)
	{
		if(as<30&&b<30&&c<30&&now<1000)
		{
			if(mi[as][b][c][now]==0)
		{
			mi[as][b][c][now]=max(s(as+1,b,c,now+a[as+b+c].a),s(as,b+1,c,now+a[as+b+c].b));
		}
		return mi[as][b][c][now];
		}
		return max(s(as+1,b,c,now+a[as+b+c].a),s(as,b+1,c,now+a[as+b+c].b));
	}
	if(as<30&&b<30&&c<30&&now<1000)
		{
			if(mi[as][b][c][now]==0)
		{
			mi[as][b][c][now]=max(s(as+1,b,c,now+a[as+b+c+1].a),max(s(as,b+1,c,now+a[as+b+c+1].b),s(as,b,c+1,now+a[as+b+c+1].c)));	
		}
		return mi[as][b][c][now];
	}
	return max(s(as+1,b,c,now+a[as+b+c+1].a),max(s(as,b+1,c,now+a[as+b+c+1].b),s(as,b,c+1,now+a[as+b+c+1].c)));
}
int main()
{	
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		A=1;
		B=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)
			{
				A=false;
			}
			if(a[i].c!=0)
			{
				B=false;
			}
		}
		if(A)
		{
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a;	
			}		
		}
		else
		{
			if(n==2)
			{
				int maxn;
				maxn=max(maxn,a[1].a+a[2].b);
				maxn=max(maxn,a[1].b+a[2].a);
				maxn=max(maxn,a[1].a+a[2].c);
				maxn=max(maxn,a[1].c+a[2].a);
				maxn=max(maxn,a[1].b+a[2].c);
				maxn=max(maxn,a[1].c+a[2].b);
				ans=maxn;
			}
			if(n==4)
			{
				int maxn;
				maxn=max(maxn,a[1].a+a[2].a+a[3].b+a[4].b);
				maxn=max(maxn,a[1].a+a[2].a+a[3].b+a[4].c);
				maxn=max(maxn,a[1].a+a[2].a+a[3].c+a[4].b);
				maxn=max(maxn,a[1].a+a[2].a+a[3].c+a[4].c);
				
				maxn=max(maxn,a[1].a+a[2].b+a[3].a+a[4].b);
				maxn=max(maxn,a[1].a+a[2].b+a[3].a+a[4].c);
				maxn=max(maxn,a[1].a+a[2].b+a[3].b+a[4].a);
				maxn=max(maxn,a[1].a+a[2].b+a[3].b+a[4].c);			
				maxn=max(maxn,a[1].a+a[2].b+a[3].c+a[4].a);
				maxn=max(maxn,a[1].a+a[2].b+a[3].c+a[4].b);
				maxn=max(maxn,a[1].a+a[2].b+a[3].c+a[4].c);
				
				maxn=max(maxn,a[1].a+a[2].c+a[3].a+a[4].b);
				maxn=max(maxn,a[1].a+a[2].c+a[3].a+a[4].c);
				maxn=max(maxn,a[1].a+a[2].c+a[3].b+a[4].a);
				maxn=max(maxn,a[1].a+a[2].c+a[3].b+a[4].b);
				maxn=max(maxn,a[1].a+a[2].c+a[3].b+a[4].c);
				maxn=max(maxn,a[1].a+a[2].c+a[3].c+a[4].a);
				maxn=max(maxn,a[1].a+a[2].c+a[3].c+a[4].b);
				
				maxn=max(maxn,a[1].b+a[2].a+a[3].a+a[4].b);
				maxn=max(maxn,a[1].b+a[2].a+a[3].a+a[4].c);
				maxn=max(maxn,a[1].b+a[2].a+a[3].b+a[4].a);
				maxn=max(maxn,a[1].b+a[2].a+a[3].b+a[4].c);
				maxn=max(maxn,a[1].b+a[2].a+a[3].c+a[4].a);
				maxn=max(maxn,a[1].b+a[2].a+a[3].c+a[4].b);
				maxn=max(maxn,a[1].b+a[2].a+a[3].c+a[4].c);
				
				maxn=max(maxn,a[1].b+a[2].b+a[3].a+a[4].a);
				maxn=max(maxn,a[1].b+a[2].b+a[3].a+a[4].c);
				maxn=max(maxn,a[1].b+a[2].b+a[3].c+a[4].a);
				maxn=max(maxn,a[1].b+a[2].b+a[3].c+a[4].c);
				
				maxn=max(maxn,a[1].b+a[2].c+a[3].a+a[4].a);
				maxn=max(maxn,a[1].b+a[2].c+a[3].a+a[4].b);
				maxn=max(maxn,a[1].b+a[2].c+a[3].a+a[4].c);
				maxn=max(maxn,a[1].b+a[2].c+a[3].b+a[4].a);
				maxn=max(maxn,a[1].b+a[2].c+a[3].b+a[4].c);
				maxn=max(maxn,a[1].b+a[2].c+a[3].c+a[4].a);
				maxn=max(maxn,a[1].b+a[2].c+a[3].c+a[4].b);
				
				maxn=max(maxn,a[1].c+a[2].a+a[3].a+a[4].b);
				maxn=max(maxn,a[1].c+a[2].a+a[3].a+a[4].c);
				maxn=max(maxn,a[1].c+a[2].a+a[3].b+a[4].a);
				maxn=max(maxn,a[1].c+a[2].a+a[3].b+a[4].b);
				maxn=max(maxn,a[1].c+a[2].a+a[3].b+a[4].c);
				maxn=max(maxn,a[1].c+a[2].a+a[3].c+a[4].a);
				maxn=max(maxn,a[1].c+a[2].a+a[3].c+a[4].b);
				
				maxn=max(maxn,a[1].c+a[2].b+a[3].a+a[4].a);
				maxn=max(maxn,a[1].c+a[2].b+a[3].a+a[4].b);
				maxn=max(maxn,a[1].c+a[2].b+a[3].a+a[4].c);
				maxn=max(maxn,a[1].c+a[2].b+a[3].b+a[4].a);
				maxn=max(maxn,a[1].c+a[2].b+a[3].b+a[4].c);
				maxn=max(maxn,a[1].c+a[2].b+a[3].c+a[4].a);
				maxn=max(maxn,a[1].c+a[2].b+a[3].c+a[4].b);
				
				maxn=max(maxn,a[1].c+a[2].c+a[3].a+a[4].a);
				maxn=max(maxn,a[1].c+a[2].c+a[3].a+a[4].b);
				maxn=max(maxn,a[1].c+a[2].c+a[3].b+a[4].a);
				maxn=max(maxn,a[1].c+a[2].c+a[3].b+a[4].b);
				ans=maxn;
			}
			else
			{
				if(B)
				{
					ans=max(s(1,0,0,a[1].a),s(0,1,0,a[1].b));
				}
				else
				ans=max(max(s(1,0,0,a[1].a),s(0,1,0,a[1].b)),s(0,0,1,a[1].c));
			}
		}
	cout<<ans<<endl;
	}
	return 0;
} 