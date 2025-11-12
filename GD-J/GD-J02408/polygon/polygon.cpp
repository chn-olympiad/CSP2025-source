#include<bits/stdc++.h>
//rp++
//ccf let me passed
//48181542
//Eason2010
//give up already
using namespace std;
int n,a[500010],i,ans;
void dfs(int sum,int _i,int num){
	if(!_i) return;
	if(sum >= a[i] << 1 and num >= 3) ans = (ans + 1) % 998244353;
	dfs(sum + a[_i - 1],_i - 1,num + 1);
	dfs(sum,_i - 1,num);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(i = n;i >= 3;i--){
		dfs(a[i],i,1);
	}
	cout << ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
