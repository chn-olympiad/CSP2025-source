#include <iostream>
#include <algorithm>
using namespace std;
long long ans;
int xin[100010];
int n;
void dfs(int x,int sum,int Max,int num){
	if(sum > Max * 2 && num >= 3)ans ++,ans %= 998244353;
	for(int i = 1;i < x;i ++)
		dfs(i,sum + xin[i],Max,num + 1); 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int ma = 0;
	for(int i = 1;i <= n;i ++){
		cin >> xin[i];
		ma = max(xin[i],ma);
	}
	if(ma == 1){
		long long num = n;
		long long sum = 1;
		for(int i = 1;i <= n - 3;i ++){
			sum *= num;
			sum %= 998244353;
			num --;
			ans += sum;
			ans %= 998244353;
		}
		ans ++;
	}else {
		sort(xin + 1,xin + 1 + n);
		for(int i = n;i >= 1;i --)
			dfs(i,xin[i],xin[i],1);
	}
	cout << ans;
	return 0;
}
