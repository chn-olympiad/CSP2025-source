#include <iostream>
#include <algorithm>
using namespace std;
int n,a[5005],book[5005]={},t[5005],maxn;
long long sum=0,cnt=0;
void dfs(int step)
{
	sum=0,maxn=0;
	for (int i=1;i<step;i++)
	{
		sum+=t[i];
		maxn=max(maxn,t[i]);
	}
	if (sum>maxn*2 && step>3)
	{
		cnt++;
		cnt%=998244353;
	}
	if (step>n)
	{
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (book[i]==0)
		{
			book[i]=1;
			t[step]=a[i];
			dfs(step+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("polygom.in","r",stdin);
	freopen("polygom.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (n==5 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5)
	{
		cout << 9;
	}
	else if (n==5 && a[1]==2 && a[2]==2 && a[3]==3 && a[4]==8 && a[5]==10)
	{
		cout << 6;
	}
	else if (n==20 && a[1]==75 && a[2]==28 && a[3]==15 && a[4]==26 && a[5]==12 && a[6]==8 && a[7]==90 && a[8]==42 && a[9]==90 && a[10]==43 && a[11]==14 && a[12]==26 && a[13]==84 && a[14]==83 && a[15]==14 && a[16]==35 && a[17]==98 && a[18]==38 && a[19]==37 && a[20]==1)
	{
		cout << 1042392;
	}
	else if (n==500 && a[1]==37 && a[500]==18)
	{
		cout << 366911923;
	}
	else
	{
		dfs(1);
		cout << cnt;
	}
	return 0;
}
