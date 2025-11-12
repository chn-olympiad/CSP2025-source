#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n,a[5005];
int C(int n,int k)
{
	return tgamma(n+1)/(tgamma(n-k+1)*tgamma(k+1));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i]!= 1)
			flag = 0;
	}
	sort(a+1,a+n+1);
	if(n == 3)
	{
		if(a[1]+a[2]>a[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if(flag)
	{
		int cnt = 1;
		for(int i = 3;i <= n;i++)
			for(int j = 2;j < n;j++)
				cnt += C(i,j);
		cout << cnt % mod;
		return 0;
	}
	cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
