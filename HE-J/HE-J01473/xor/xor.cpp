#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 500005

int a[MAX],n,k;

int tou[MAX],wei[MAX],ans;

void solve()
{
	for(int L=1;L<=n;L++)
	{
		for(int r=L;r<=n;r++)
		{
			if((tou[n]^tou[L-1]^wei[r+1])==k)
			{
				ans++;
				L=r;
				break;
			}
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	tou[0]=0;
	wei[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		tou[i]=(tou[i-1] xor a[i]);
		wei[n-i+1]=(wei[n-i+2] xor a[n-i+1]);
	}
	solve();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
