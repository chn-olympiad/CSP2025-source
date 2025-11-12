# include <bits/stdc++.h>
using namespace std;

bool f=false;
int n,a[5005],xx,g[5005],cntx,x[5005];
long long sumw;

void dg(int cnt,int sum,int maxid)
{
	if (f == true) return;
	if (sum <= 2*g[maxid])
	{
		x[cnt-1]++;
		x[cnt] = x[cnt-1]+1;
		/*if (x[cnt-1] == n) 
		{
			x[cnt-2]++;
			x[cnt-1]=x[cnt-2]+1;
		}
		if (x[cnt-2] == n) 
		{
			x[cnt-3]++;
			x[cnt-2]=x[cnt-3]+1;
			x[cnt-1]=x[cnt-2]+1;
		}
		if (x[cnt-3] == n) 
		{
			return;
		}*/
		int p = 1;
		while(x[cnt-p] == n)
		{
			//if ( x[cnt-p] != n) break;
			x[cnt-p-1]++;
			for (int i = p; i>= 1; i--)
			{
				x[cnt-i]=x[cnt-i-1]+1;
			}
			if (p== n-1 && x[1] == n)
			{
				f = true;
				return;
			}
			//if (x[cnt-p]!= n)break;
			p++;
		}
	}
	else 
	{
		sumw++;
		x[cnt]++;
	}
	int sumy=0,mae;
	for (int i = 1; i <= cnt; i++)
	{
		sumy += g[x[cnt]];
		if (i ==cnt)mae = x[cnt];
	}
	dg(cnt,sumy,mae);


}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> xx;
		a[xx]++;
	}
	for (int i = 1; i <= 5000; i++)
	{		
		for (int j = 1; j <= a[i];j++)
		{
			g[++cntx] = i;
		}
	}
	
	for (int i = 3; i <= n; i++)
	{
		int sumt = 0;
		for (int j = 1; j <= i; j++)
		{
			sumt+= g[j];
			x[j] = j;
		}
		dg(i,sumt,i);
		sumw %= 998244353;
	
	
	}
	cout << sumw;
	return 0;
}
