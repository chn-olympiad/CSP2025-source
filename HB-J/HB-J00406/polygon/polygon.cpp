#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5005;
int a[N];
int ans;
int b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	if(n < 3){
		cout<<0;
		return 0;
	}
	if(n == 3){
		sort(a + 1,a + n + 1);
		int sum = 0;
		for(int i = 1;i <= n;i ++){
			sum += a[i];
		}
		if(sum > a[n] * 2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i = 1;i <= n - 2;i ++){
		for(int j = i + 1;j <= n;j ++){
			int ind = 1,sum = 0;
			for(int k = i;k <= j;k ++){
				b[ind ++] = a[k];
				sum += a[k];
			}
			sort(b + 1,b + ind);
			if(sum > b[ind - 1]){
				ans ++;
			}
		}
	}
	cout<<ans % 998 % 244 % 353;
	return 0;
}
