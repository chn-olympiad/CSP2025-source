#include<bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int fi,se,th,maxn;
}a[1009876];
bool cmp(node x,node y)
{
	return x.fi > y.fi;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n,sum=0;
		int b= 0,c= 0,d=0;
		cin >> n;
		for(int i = 1; i <= n;i++)
		{
			cin >> a[i].fi >> a[i].se >> a[i].th;
			a[i].maxn=max(a[i].fi,max(a[i].se,a[i].th));
			if(a[i].se == 0 && a[i].th==0)
			{
				sort(a+1,a+n+1,cmp);
				for(int j = 1; j <= n/2; j++)
				{
					sum+=a[j].fi;
				}
				cout << sum;
				return 0;
			}
			if(a[i].maxn == a[i].fi && b <= n/2-1)
			{
				b++;
				sum+=a[i].maxn;
			}
			else if(a[i].maxn == a[i].fi && b >= n/2)
			{
				a[i].maxn = max(a[i].se,a[i].th);
				if(a[i].maxn == a[i].se && c <= n/2-1)
				{
					c++;
					sum+=a[i].se;
				 } 
				 else if(a[i].maxn == a[i].se && c >= n/2)
				 {
				 	d++;
				 	sum+=a[i].th;
				 }
				 else if(a[i].maxn == a[i].th && d <= n/2-1)
				{
					d++;
					sum+=a[i].th;
				 } 
				 else if(a[i].maxn == a[i].th && d >= n/2)
				 {
				 	c++;
				 	sum+=a[i].se;
				 }
			}
			else if(a[i].maxn == a[i].se && c <= n/2-1)
			{
				c++;
				sum+=a[i].maxn;
			}
			else if(a[i].maxn == a[i].se && c >= n/2)
			{
				a[i].maxn = max(a[i].fi,a[i].th);
				if(a[i].maxn == a[i].fi && b <= n/2-1)
				{
					b++;
					sum+=a[i].fi;
				 } 
				 else if(a[i].maxn == a[i].fi && b >= n/2)
				 {
				 	d++;
				 	sum+=a[i].th;
				 }
				 else if(a[i].maxn == a[i].th && d <= n/2-1)
				{
					d++;
					sum+=a[i].th;
				 } 
				 else if(a[i].maxn == a[i].th && d >= n/2)
				 {
				 	b++;
				 	sum+=a[i].fi;
				 }
			}
			 else if(a[i].maxn == a[i].th && d <= n/2-1)
			{
				d++;
				sum+=a[i].maxn;
			}
			else if(a[i].maxn == a[i].th && d >= n/2)
			{
				a[i].maxn = max(a[i].se,a[i].fi);
				if(a[i].maxn == a[i].se && c <= n/2-1)
				{
					c++;
					sum+=a[i].se;
				 } 
				 else if(a[i].maxn == a[i].se && c >= n/2)
				 {
				 	b++;
				 	sum+=a[i].fi;
				 }
				 else if(a[i].maxn == a[i].fi && b <= n/2-1)
				{
					b++;
					sum+=a[i].fi;
				 } 
				 else if(a[i].maxn == a[i].th && d >= n/2)
				 {
				 	c++;
				 	sum+=a[i].se;
				 }
			}
		}
		cout << sum << endl;
	}
	return 0;
 } 
