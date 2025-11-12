/*
int t;
int x,y,z;
struct node{
	int a1;
	int a2;
	int a3;
	int maxx;
	int maxj;
	int cha;
} a[100005];
bool com1(node x,node y)
{
	return (x.a1>y.a1?1:0);
}
bool com2(node x,node y)
{
	return (x.a2>y.a2?1:0);
}
bool com3(node x,node y)
{
	return (x.a3>y.a3?1:0);
}
bool com(node x,node y)
{
	return (x.maxj>y.maxj?1:0);
}
node t1[100005],t2[100005],t3[100005];
signed main(){
	freopen("club4.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin >> t;
	for(int q = 1;q<=t;q++)
	{
		int n = 0;
		int ans = 0;
		int t1s=0,t2s=0,t3s=0;
		cin >> n;
		int maxn = n/2;
		for(int i = 1;i<=n;i++)
		{
			cin >> x >> y >> z;
			if(x>y&&x>z)
			{
				t1[++t1s].a1 = x;  
				t1[t1s].a2 = y;  
				t1[t1s].a3 = z;  
				t1[t1s].maxj = max(x-y,x-z);
				t1[t1s].maxx = y>z?2:3;
			}
			else if(y>x && y>z)
			{
				t2[++t2s].a1 = x;  
				t2[t2s].a2 = y;  
				t2[t2s].a3 = z;  
				t2[t2s].maxj = max(y-x,y-z);
				t2[t2s].maxx = x>z?1:3;
			}
			else
			{
				t3[++t3s].a1 = x;  
				t3[t3s].a2 = y;  
				t3[t3s].a3 = z;  
				t3[t3s].maxj = max(z-x,z-y);
				t3[t3s].maxx = x>y?1:2;
			}
		}
		if(t1s>maxn)
		{
			for(int i = maxn+1;i<=t1s;i++)
			{
				t1[i-maxn].maxj = max(t1[i-maxn].maxj,t1[i-maxn].a1 - t1[i].a1);
			}
			sort(t1+1,t1+1+t1s,com);
			for(int i = maxn+1;i<=t1s;i++)
			{
				if(t1[i].maxx == 2)
				{
					t2[++t2s].a1 = t1[i].a1;  
					t2[t2s].a2 = t1[i].a2;  
					t2[t2s].a3 = t1[i].a3;  
					t2[t2s].maxj = t1[i].a2 - t1[i].a3;
				}
				else
				{
					t3[++t3s].a1 = t1[i].a1;  
					t3[t3s].a2 = t1[i].a2;  
					t3[t3s].a3 = t1[i].a3;  
					t3[t3s].maxj = t1[i].a3-t1[i].a2;
				}
			}
			t1s = maxn;
		}
		sort(t2+1,t2+t2s+1,com);
		if(t2s>maxn)
		{
			for(int i = maxn+1;i<=t2s;i++)
			{
				t2[i-maxn].maxj = max(t2[i-maxn].maxj,t2[i-maxn].a2 - t1[i].a2);
			}
			sort(t2+1,t2+1+t2s,com2);
			for(int i = maxn+1;i<=t2s;i++)
			{
				if(t2[i].maxx == 1)
				{
					t1[++t1s].a1 = t2[i].a1;  
					t1[t1s].a2 = t2[i].a2;  
					t1[t1s].a3 = t2[i].a3;  
					t1[t1s].maxj = t2[i].a1-t2[i].a3;
				}
				else
				{
					t3[++t3s].a1 = t2[i].a1;  
					t3[t3s].a2 = t2[i].a2;  
					t3[t3s].a3 = t2[i].a3;  
					t3[t3s].maxj = t2[i].a3-t2[i].a1;
				}
			}
			t2s = maxn;
		}
		sort(t3+1,t3+t3s+1,com);
		if(t3s>maxn)
		{
			for(int i = maxn+1;i<=t3s;i++)
			{
				t3[i-maxn].maxj = max(t3[i-maxn].maxj,t3[i-maxn].a3 - t3[i].a3);
			}
			sort(t1+3,t1+3+t3s,com3);
			for(int i = maxn+1;i<=t3s;i++)
			{
				if(t3[i].maxx == 1)
				{
					t1[++t1s].a1 = t3[i].a1;  
					t1[t1s].a2 = t3[i].a2;  
					t1[t1s].a3 = t3[i].a3;  
					t1[t1s].maxj = t3[i].a1 - t3[i].a2;
				}
				else
				{
					t2[++t2s].a1 = t3[i].a1;  
					t2[t2s].a2 = t3[i].a2;  
					t2[t2s].a3 = t3[i].a3;  
					t2[t2s].maxj = t3[i].a2-t3[i].a1;
				}
			}
			t3s = maxn;
		}
		for(int i = 1;i<=t1s;i++)
		{
			ans += t1[i].a1;
		}
		for(int i = 1;i<=t2s;i++)
		{
			ans += t2[i].a2;
		}
		for(int i = 1;i<=t3s;i++)
		{
			ans += t3[i].a3;
		}
		cout << ans << endl;
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
#define long long int
int a[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int q = 1;q<=t;q++)
	{
		int n;
		cin >> n;
		int a1,a2,a3,ans = 0;
		for(int i = 1;i<=n;i++)
		{
			cin >> a1 >> a2 >> a3;
			a[i] = a1;
		}
		sort(a,a+n+1);
		for(int i = n;i>(n/2);i--)
		{
			cout << a[i] <<endl;
			ans+=a[i];
		}
		cout << ans << endl;
	}
}

