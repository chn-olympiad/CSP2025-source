#include <iostream>
#include <cstdio>

using namespace std;

long long a[5005]={0},ans = 0,n;

void f(long long x,long long max,long long sum){
	if(a[x] > max)max = a[x];
	sum += a[x];
	if(sum > (2 * max))ans = (ans + 1) % 998244353;
	for(int i = x + 1;i <= n;i++)f(i,max,sum);
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)cin >> a[i];
	f(0,0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
