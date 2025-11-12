#include <bits/stdc++.h>
using namespace std;

int f[2][500], a[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n, k;
	bool flag1 = 1, flag = 1;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]>1)flag = 0;
		else if(a[i]>0)flag1 = 0;
	}
	if(!flag){
		memset(f,-0x3f,sizeof(f));
	for(int i = 0; i <= n; i++)
	f[i][0]=0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= 255; j++)
		{
			if(j==k)
			f[i&1][j]=max(f[(i-1)&1][j],f[(i-1)&1][j^a[i]]+1);
			else
			f[i&1][j]=max(f[(i-1)&1][j],f[(i-1)&1][j^a[i]]);
		}
	}
	cout << f[n&1][k];
	}
	else if(!flag1)
	{
		if(k==1){
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(a[i]==k)cnt++;
			cout << cnt;
		}
		else
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i]==0)cnt++;
				else if(a[i-1]==1){
					a[i-1]=a[i]=0;
					cnt++;
				}
			}
			cout << cnt;
		}
	}
	else
	{
		cout << n/2;
	}
}
