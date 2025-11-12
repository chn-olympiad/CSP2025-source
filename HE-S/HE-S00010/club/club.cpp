#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int bumen[5];
int t,n;
int xinren[5];
struct jiegou{
	int b1,b2,b3;
}bbb[N];
int maxn[5];
void f(int x,int y,int z)
{
	if(x>=y && y>=z) 
	{
		xinren[1]=1;
		xinren[2]=2;
		xinren[3]=3;
		maxn[1]=x;
		maxn[2]=y;
		maxn[3]=z;
		return;
	}
	else if(x>=z && z>=y)
	{
		xinren[1]=1;
		xinren[2]=3;
		xinren[3]=2;
		maxn[1]=x;
		maxn[3]=z;
		maxn[2]=y;
		return;
	}
	else if(y>=x&&x>=z)
	{
		xinren[1]=2;
		xinren[2]=1;
		xinren[3]=3;
		maxn[2]=y;
		maxn[1]=x;
		maxn[3]=z;
		return;
	}
	else if(y>=z&&z>=x)
	{
		xinren[1]=2;
		xinren[2]=3;
		xinren[3]=1;
		maxn[2]=y;
		maxn[3]=z;
		maxn[1]=x;
		return;
	}
	else if(z>=x && x>=y)
	{
		xinren[1]=3;
		xinren[2]=1;
		xinren[3]=2;
		maxn[3]=z;
		maxn[1]=x;
		maxn[2]=y;
		return;
	}
	else if(z>=y&&y>=x)
	{
		xinren[1]=3;
		xinren[2]=2;
		xinren[3]=1;
		maxn[3]=z;
		maxn[2]=y;
		maxn[1]=x;
		return;
	}
}
bool cmp(jiegou x,jiegou y)
{
	return x.b1<=y.b1;
}
int ans[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int cnt[5]={0,0,0};
		cin >> n;
		memset(bumen,0,sizeof(bumen));
		for(int j=1;j<=n;j++)
			cin >> bbb[j].b1 >> bbb[j].b2 >> bbb[j].b3;
		sort(bbb+1,bbb+n+1,cmp);
		for(int j=1;j<=n;j++)
		{
			f(bbb[j].b1,bbb[j].b2,bbb[j].b3);
			if(cnt[xinren[1]]<(n/2))
			{
				bumen[xinren[1]]+=maxn[xinren[1]];
				cnt[xinren[1]]++;
			}
			else if(cnt[xinren[2]]<(n/2))
			{
				bumen[xinren[2]]+=maxn[xinren[2]];
				cnt[xinren[2]]++;
			}
			else if(cnt[xinren[3]]<(n/2))
			{
				bumen[xinren[3]]+=maxn[xinren[3]];
				cnt[xinren[3]]++;
			}
		}
		ans[i]=bumen[1]+bumen[2]+bumen[3];
	}
	for(int i=1;i<=t;i++) 
		cout << ans[i] << endl;
	return 0;
} 
