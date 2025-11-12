
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y,z;
	int id;
}a[100005];
bool cmp1(node a,node b)
{
	return a.x > b.x;
}
bool cmp2(node a,node b)
{
	return a.y > b.y;
}
bool cmp3(node a,node b)
{
	return a.z > b.z;
}
void solve()
{
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	bool judge1 = false,judge2 = false;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].y != 0)
		{
			judge1 = true;
			
		}
		if(a[i].z != 0)
		{
			judge1 = true;
			judge2 = true;
		}
		a[i].id = i;
	}
	long long ans = 0;
	if(!judge2)
	{
		int xx = 0,yy = 0;
		for(int i = 1;i<=n;i++)
		{
			if(xx > n / 2)
			{
				ans += a[i].y;
				continue;
			}
			else if(yy > n / 2)
			{
				ans += a[i].x;
				continue;
			}
			if(a[i].x > a[i].y)
			{
				ans += a[i].x;
				xx ++;
			}
			else if(a[i].x < a[i].y)
			{
				ans += a[i].y;
				yy ++;
			 } 
			 else
			 {
			 	ans += a[i].y;
			 	if(xx < yy)
			 	{
			 		xx ++;
				 }
				 else
				 {
				 	yy ++;
				 }
			 }
		}
		cout<<ans<<endl;
	}
	else if(!judge1)
	{
		sort(a + 1,a + n + 1,cmp1);
		for(int i = 1;i<=n/2;i++)
		{
			ans += a[i].x;
		}
		cout<<ans<<endl;
	}
	else if(n == 2)
	{
		cout<<max({a[1].x + a[2].y,a[1].x + a[2].z,a[1].y + a[2].x,a[1].y + a[2].z ,a[1].z + a[2].x,a[1].z + a[2].y})<<"\n";
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			ans += max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<ans<<endl;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}
