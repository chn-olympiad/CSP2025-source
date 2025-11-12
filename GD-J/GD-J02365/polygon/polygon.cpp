#include <bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,max_n = -1,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i]=a[i]+a[i-1];
		if(max_n<a[i])max_n=a[i];
	}
	if(n==3)cout << 1;
	else{
		for(int i = 1;i <= n-3;i++){
			for(int j = i+3;j<=n;j++){
				max_n=-1;
				for(int k = i;k <= j;k++){
					if(max_n<a[i])max_n = a[i];
				}
				if(b[j]-b[i-1]>max_n)ans++;
			}
		}
		cout << ans;
	}
	return 0;
} 
