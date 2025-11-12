#include<iostream> 
using namespace std;
long long n , a[5005] , ans = 0 ;
bool flag[5005];
void dfs(int cnt , long long maxai , long long sum ,int lasti)
{
	if(cnt >= 3 && maxai * 2 < sum){
		ans++;
	}
	for(int i = lasti + 1;i <= n;i++)
	{
		if(!flag[i]){
			flag[i] = 1;
			dfs(cnt + 1 , max(maxai , a[i]) , sum + a[i] , i);
			flag[i] = 0;
		}
	}
	return ;//666
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n <= 2)
	{
		cout << 0;
		return 0;
	}else if(n == 3)
	{
		cout << (((max(a[1],max(a[2],a[3])) * 2) < (a[1] + a[2] + a[3])) ? 1 : 0);
		return 0;
	}else if(n <= 21)
	{
		dfs(0 , 0, 0 , 0);
		cout << ans;
		return 0;
	}
	return 0;
}
/*
It look like DP;
but I have not mind
1~3 I can DA'BIAO !!!
can I use chinese ?
10:58
maybe I get 12pts.
It OK to 260 pts get CSP_J YIDENG ?
I hope my T2 & T1 is AC;
11:01 
when n <= 20 
I can dfs;
Just do it!
my be it can dui'pai
11:15
my dfs is ac the yang'li !!!
I will get 40 pts;
Let's check now;
11:18
polygon3 is OK !!!
Maybe I will get to YI'DENG ?
I LOVE CCf 
11:21
I can get T4 40 pts now;
let me write T3;
 
*/
