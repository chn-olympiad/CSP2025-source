#include<bits/stdc++.h>
using namespace std;
int t,n,one,two,three;
const int N=1e5+10;
struct Node 
{
	int fi,se,th;
}a[N];
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
bool cmp(Node a,Node b)
{
	if(a.fi!=b.fi) return a.fi>b.fi;
	else if(a.se!=b.se) return a.se>b.se;
	return a.th>b.th;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		int ans=0,one=0,two=0,three=0,ans1=0,ans2=0,ans3=0;
		memset(a,0,sizeof(a));
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i].fi=read();
			a[i].se=read();
			a[i].th=read();
			ans1+=a[i].fi;
			ans2+=a[i].se;
			ans3+=a[i].th;
		}
		sort(a+1,a+n+1,cmp);
		if(ans1<ans2)
		{
			for(int i=1;i<=n;i++)
			{
				swap(a[i].fi,a[i].se);
			}
			swap(ans1,ans2);
		}
		if(ans2<ans3)
		{
			for(int i=1;i<=n;i++)
			{
				swap(a[i].se,a[i].th);
			}
			swap(ans2,ans3);
		}
		if(ans1<ans2)
		{
			for(int i=1;i<=n;i++)
			{
				swap(a[i].fi,a[i].se);
			}
			swap(ans1,ans2);
		}
		
		for(int i=1;i<=n-1;i++)
		{
			int p=0;
			while(p==0)
			{
				if(one<n/2&&a[i].fi-a[i+1].fi>=a[i].se-a[i+1].se) 
				{
					ans+=a[i].fi;
					one++;
					p++;
					break;
				}
				if(two<n/2&&a[i].se-a[i+1].se>=a[i].th-a[i+1].th) 
				{
					ans+=a[i].se;
					two++;
					p++;
					break;
				}
				if(three<n/2&&a[i].th-a[i+1].th>=a[i].fi-a[i+1].fi)
				{
					ans+=a[i].th;
					three++;
					p++;
					break;
				}
			}
		}
		if(one<n/2&&max(max(a[n].fi,a[n].se),a[n].th)==a[n].fi) ans+=a[n].fi;
		else if(two<n/2&&max(max(a[n].fi,a[n].se),a[n].th)==a[n].se) ans+=a[n].se;
		else if(three<n/2&&max(max(a[n].fi,a[n].se),a[n].th)==a[n].th) ans+=a[n].th;
		cout<<ans<<endl;
	}
	return 0;
}
