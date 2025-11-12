#include<bits/stdc++.h>
using namespace std;
int t;
int n,maxn = -1;
struct per
{
	int a1,a2,a3;
}arr[100005];
bool cmp(per xx,per yy)
{
	return xx.a1 > yy.a1;
}
bool cmp2(per x,per y)
{
	return x.a1 - x.a2 > y.a1 - y.a2;
}
void dfs(int s,int sum,int suma,int sumb,int sumc)
{
	if(s > n)
	{
		maxn = max(maxn,sum);
		return;
	}
	if(suma + 1 <= n / 2) dfs(s + 1,sum + arr[s].a1,suma + 1,sumb,sumc);
	if(sumb + 1 <= n / 2) dfs(s + 1,sum + arr[s].a2,suma,sumb + 1,sumc);
	if(sumc + 1 <= n / 2) dfs(s + 1,sum + arr[s].a3,suma,sumb,sumc + 1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int fla = 1,flb = 1;
		maxn = -1;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> arr[i].a1 >> arr[i].a2 >> arr[i].a3;
			if(arr[i].a2 != 0 || arr[i].a3 != 0) fla = 0;
			if(arr[i].a3 != 0) flb = 0;
		}
		if(n <= 15)
		{
			dfs(1,0,0,0,0);
			cout << maxn << endl;
		}
		if(fla == 1)
		{
			sort(arr + 1,arr + n + 1,cmp);
			long temp = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				temp += arr[i].a1;
			}
			cout << temp << endl;
		}
		else if(flb == 1)
		{
			long tmp = 0;
			sort(arr + 1,arr + n + 1,cmp2);
			for(int i = 1;i <= n / 2;i++)
			{
				tmp += arr[i].a1;
			}
			for(int i = n / 2 + 1;i <= n;i++)
			{
				tmp += arr[i].a2;
			}
			cout << tmp << endl;
		}
		
	}
	return 0;
 } 
 //Ren5Jie4Di4Ling5%
