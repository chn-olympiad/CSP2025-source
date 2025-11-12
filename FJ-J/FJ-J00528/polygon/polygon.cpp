#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n <= 20){
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		for(int i = 0;i < (1 << n);i++){
			int sum = 0,maxn = 0;
			for(int j = 1;j <= n;j++)
				if(i & (1 << (j - 1))){
					sum += a[j];
					maxn = max(maxn,a[j]); 
				}
			if(sum > maxn * 2)
				ans++;
		}
		cout << ans << "\n"; 
	}
	return 0;
}

