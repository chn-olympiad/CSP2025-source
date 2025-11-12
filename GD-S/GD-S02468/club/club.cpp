#include<bits/stdc++.h>
using namespace std;
int n, t, l[3], ans;
bool flaga,flagb;
struct people{
	int a,b,c,tot;
	
};
bool pd(people a,people b){
	return a.tot > b.tot; 
}


void solve()
{
	cin >> n;
	people r[n];
	for(int i = 1; i <= n; i++)
	{
		cin >> r[i].a  >> r[i].b >> r[i].c;
		
		r[i].tot = r[i].a + r[i].b + r[i].c;
		if(r[i].tot > r[i].a)
			flaga =true;  
		if(r[i].c)
			flagb = true;
	}
	sort(r + 1,r + n + 1, pd);
	if(!flaga)
	{
		for(int i = 1; i <= n/2; i++)
		{
			ans += r[i].a;
		}
		cout << ans << endl;
		return;
	}
	else if(!flagb)
	{
		for(int i = 1;i <= n; i++)
		{
			
			if(l[1] > (n/2))
			{
				ans+=r[i].b; 
			}
			if(l[2] > (n/2))
			{
				ans+=r[i].a;
			}
			else
			{
				if(max(r[i].a,r[i].b) == r[i].a && l[1] < (n/2))
				{
					l[1]++;ans+=r[i].a;
				}
				else
				{
					l[2]++;ans+=r[i].b;
				}
			}
		}
		cout << ans << endl;
		return;
	}
	for(int i = 1; i <= n; i++)
	{

		if(max(r[i].a,max(r[i].b,r[i].c)) == r[i].a && l[1] < (n/2))
		{
			l[1]++;ans+=r[i].a;
		}
		else if (max(r[i].a,max(r[i].b,r[i].c)) == r[i].c && l[3] < (n/2))
		{
			l[3]++;ans+=r[i].c;
		}
		else if (max(r[i].a,max(r[i].b,r[i].c)) == r[i].b && l[2] < (n/2))
		{
			l[2]++;ans+=r[i].b;
		}
		else
		{
			l[1]++;ans+=r[i].a;
		}
	}

	cout << ans << endl;
	
	return;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	
	for(int k_ = -1; k_ <= t+1;k_++)
	{
		
		l[1] = l[2] = l[3] = 0;
		ans = 0;
		solve();
	}
	return 0;
}
