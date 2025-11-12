#include<bits/stdc++.h> 
using namespace std;
const int N = 1e6;
int n;
int a[N],b[N];
int ans,num,sum;
int j = 1;
void f(int x,int maxn){
	if(x >= 4){
		if(sum > maxn * 2){
			ans = (ans % 998244353) + 1;
		}	
	}
	if(x > n)
		return;
	int i = x;
	while(i <= n){
		sum += a[i];
		if(a[i] > maxn)
			maxn = a[i];
		f(i + 1,maxn);
		sum -= a[i];
		i++;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	f(1,-1);
	cout << ans;
	return 0;
}
