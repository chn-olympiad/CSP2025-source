#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum[5010],cnt = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i] = a[i]+sum[i-1];
	}
	if(n == 3){
		if(a[1]+a[2] > a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(n <= 5){
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(sum[j]-sum[i]-a[j] > a[j]){
					cnt++;
				}
			}
		}
		cout<<cnt*3;
	}
	else{
		int m = n-1;
		while(m >= 3){
			if(sum[m] >= a[n]){
				cnt += (n-m)*(n-m+1)/2;
				m--;
			}
			else{
				if(m = n-1){
					n--;
				}
				else{
					for(int i = 1;i <= n-m;i++){
						if(sum[i+m]-sum[i] >= a[n]){
							cnt += n-m-i;
							break;
						}
					}
				}
			}
		}
		cout<<cnt;
	}
}
