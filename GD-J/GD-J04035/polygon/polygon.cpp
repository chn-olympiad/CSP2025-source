#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mo=998244353;
ll n,a[5005],zd=INT_MIN,k,s,t;
ll c[5005][5005];
bool f=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	c[1][0]=c[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		while(s<=a[i]*2 && k<i-1) k++,s+=a[k];
		if(t==0 && f==0) f=1;
		else
		{
			for(int j=k;j<i;j++) t=(t+c[i][j])%mo;
		}
		
	}
	cout << t;

	return 0;
}
/*
Rp++
T4比T3简单一点点？
初测：
T1红+~橙
T2橙
T3黄+~绿+
T4黄~绿
总结：小R是一个3岁小孩(?，Ta喜欢玩数字字母块和小木棍，Ta在csp-j的考场座位上拼数字，再把这些数字做异或和，玩累了就拿小木棍拼多边形(doge

*/ 
