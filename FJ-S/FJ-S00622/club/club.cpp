#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int dvr[100005];
int cnt[6];
int n,T;
int read()
{
	char ch = getchar();
	while(ch == '\n' || ch == ' ') ch = getchar();
	int f = 1,x = 0;
	while(ch == '-') f = -f,ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch - '0'),ch = getchar();
	return f * x; 
}
int suma(int i)
{
	return a[i][1] + a[i][2] + a[i][3];
}
int maxa(int i)
{
	return max(max(a[i][1],a[i][2]),a[i][3]);
}
int mina(int i)
{
	return min(min(a[i][1],a[i][2]),a[i][3]);
}
int mida(int i)
{
	return suma(i) - maxa(i) - mina(i);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		scanf("%d",&n);
		int maxd = 0;
		int ans = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i = 1;i <= n;i++)
		{
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
//			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][1] == maxa(i)) cnt[1]++;
			else if(a[i][2] == maxa(i)) cnt[2]++;
			else cnt[3]++;
			ans += maxa(i);
		}
		if(cnt[1] <= n / 2 && cnt[2] <= n/ 2 && cnt[3] <= n / 2)
		{
			cout << ans << endl;
			continue;
		}
		if(cnt[1] > n / 2) maxd = 1;
		else if(cnt[2] > n / 2) maxd = 2;
		else maxd = 3;
		int l = 0;
		for(int i = 1;i <= n;i++)
			if(maxa(i) == a[i][maxd]) dvr[++l] = maxa(i) - mida(i);
		sort(dvr + 1,dvr + l + 1);
		for(int i = 1;i <= cnt[maxd] - n / 2;i++) ans -= dvr[i];
		printf("%d\n",ans);
	}
	return 0;
}
