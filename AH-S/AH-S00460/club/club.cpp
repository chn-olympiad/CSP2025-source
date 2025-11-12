#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
int maxv=0,c1,c2,c3;
int x1,x2,x3;
int sumx;
void dfs1(int dep,int sum)
{
	if(dep>n)
	{
		if((c1>n/2)||(c2>n/2)||(c3>n/2)) return;
		maxv=max(maxv,sum);
	}
	c1++;
	dfs1(dep+1,sum+a[dep][1]);
	c1--;
	c2++;
	dfs1(dep+1,sum+a[dep][2]);
	c2--;
	c3++;
	dfs1(dep+1,sum+a[dep][3]);
	c3--;
}
void solve1()
{
	maxv=c1=c2=c3=0;
	dfs1(1,0);
	cout<<maxv<<endl;
	return;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int p,q,r;
		p=a[i][1],q=a[i][2],r=a[i][3];
		if(p>q&&p>r) x1++,sumx+=p;
		if(q>p&&q>r) x2++,sumx+=q;
		if(r>p&&r>q) x3++,sumx+=r;
	}
	if(n<=10) solve1();
	if(x1<=n/2&&x2<=n/2&&x3<=n/2)
	{
		cout<<sumx<<endl;
		return;
	}
	int o[4]={0,0,0,0};
	int sum2=0;
	for(int i=1;i<=n;i++)
	{
		int m,n2,l,x=1,y=2,z=3;
		m=a[i][1],n2=a[i][2],l=a[i][3];
		if(m>n2)
		{
			swap(m,n2);
			swap(x,y);
		} 
		if(n2>l)
		{
			swap(n2,l);
			swap(y,z);
		}
		
		if(m>n2)
		{
			swap(m,n2);
			swap(x,y);
		}
		if(o[z]<n/2) o[z]++,sum2+=l;
		else if(o[y]<n/2) o[y]++,sum2+=n2;
		else o[x]++,sum2+=m;
	}
	cout<<sum2<<endl;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
		solve();
	return 0;
}
