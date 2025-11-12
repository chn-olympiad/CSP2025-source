#include<bits/stdc++.h>
using namespace std;

int a[5000];
int jc(int n)
{
	int sum =1;
	while(n){
		sum *= n;
		n--;
	}
	return sum;
}
bool cmp(int x,int y)
{
	return x>y;
}
long long ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(a[1] == 1){
		for(int i=3;i<=n;i++){
			ans += jc(n) / jc(n-i) / jc(i);
			ans = ans%998244353; 
		}
	}
	else{
		if(a[1] < a[2]+a[3]){
			ans = 1;
		}
		else{
			ans = 0;
		}
	}
	cout << ans;
	return 0;
}
