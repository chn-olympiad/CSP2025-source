#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T,n,a1[N],a2[N],a3[N],tmp2,tmp3,maxx;
struct str
{
	int k,num;
}b[N];
void dfs(int id,int k1,int k2,int k3,int ans)
{
	if(id == n + 1)
	{
		maxx = max(maxx,ans);
		return;
	}
	if(k1 < n / 2) dfs(id + 1,k1 + 1,k2,k3,ans + a1[id]);
	if(k2 < n / 2) dfs(id + 1,k1,k2 + 1,k3,ans + a2[id]);
	if(k3 < n / 2) dfs(id + 1,k1,k2,k3 + 1,ans + a3[id]);
}
bool cmp(str x,str y)
{
	return x.k > y.k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T -- )
	{
		maxx = 0,tmp2 = 0,tmp3 = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			tmp2 = max(tmp2,a2[i]);
			tmp3 = max(tmp3,a3[i]);
		}
		if(tmp2 == 0 && tmp3 == 0)
		{
			sort(a1 + 1,a1 + n + 1);
			for(int i=n/2+1;i<=n;i++)
			{
				maxx += a1[i];
			}
			cout<<maxx<<endl;
		}
		if(tmp2 != 0 && tmp3 == 0)
		{
			for(int i=1;i<=n;i++)
			{
				b[i].k = a1[i] - a2[i];
				b[i].num = i;
			}
			sort(b + 1,b + n + 1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(i <= n / 2) maxx += a1[b[i].num];
				else maxx += a2[b[i].num];
			}
			cout<<maxx<<endl;
		}
		else
		{
			dfs(1,0,0,0,0);
			cout<<maxx<<endl;
		}
	}
}