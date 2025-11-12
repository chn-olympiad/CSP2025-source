#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;

int a[5005], f[5005][5005], cnt=0;
int n;

int dfs(int step,int sum,int fa,int num)
{
	//if(num+n<2+step)return;
	if(step>n){
		if(num>=3&&sum>2*a[fa]){
			return 1;
			//cout << sum << " " << fa << " " << num << "\n"; 
		}
		return 0;
	}
	long long cnt = dfs(step+1,sum,fa,num);
	cnt=(cnt+dfs(step+1,sum+a[step],step,num+1))%p;
	return cnt;
} 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	cout << dfs(1,0,0,0);
}
