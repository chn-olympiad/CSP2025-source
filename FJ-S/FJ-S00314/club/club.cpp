#include <bits/stdc++.h>
using namespace std;
int a[200001][10];
int one[200001],cnt1=0,two[200001],cnt2=0,three[200001],cnt3=0;
int cost[200001];
bool cmp(int a,int b)
{
	return cost[a] < cost[b];
}
int read()
{
	int base=1,res=0;
	char ch=getchar();
	while(!(ch == '-'||'0' <= ch&&ch <= '9')) ch=getchar();
	if(ch == '-') 
	{
		base=-1;
		ch=getchar();
	}
	while('0' <= ch&&ch <= '9')
	{
		res *= 10;
		res += ch-'0';
		ch=getchar();
	}
	return res*base;
}
void solve()
{
	cnt1=0,cnt2=0,cnt3=0;
	int n,sat=0;
	n = read();
	for(int i=1;i<=n;i++) 
	{
		a[i][1]=read();a[i][2]=read();a[i][3]=read();
		if(a[i][1] >= a[i][2]&&a[i][1] >= a[i][3])
		{
			one[++cnt1]=i;
			cost[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			sat += a[i][1];
		}
		else if(a[i][2] >= a[i][1]&&a[i][2] >= a[i][3])
		{
			two[++cnt2]=i;
			cost[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			sat += a[i][2];
		}
		else if(a[i][3] >= a[i][1]&&a[i][3] >= a[i][2])
		{
			three[++cnt3]=i;
			cost[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			sat += a[i][3];
		}
	}
	if(cnt1 <= n/2&&cnt2 <= n/2&&cnt3 <= n/2) 
	{
		cout << sat << endl;
		return ;
	}
	else if(cnt1 > n/2)
	{
		sort(one+1,one+1+cnt1,cmp);
		for(int i=1;i<=cnt1-n/2;i++) sat -= cost[one[i]];
	}
	else if(cnt2 > n/2)
	{
		sort(two+1,two+1+cnt2,cmp);
		for(int i=1;i<=cnt2-n/2;i++) sat -= cost[two[i]];
	}
	else if(cnt3 > n/2)
	{
		sort(three+1,three+1+cnt3,cmp);
		for(int i=1;i<=cnt3-n/2;i++) sat -= cost[three[i]];
	}
	cout << sat << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--) solve();
	return 0;
}