#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans,c=1,cnt = 3,d;
	for(int i = 1;i<= n;i++){
		for(int j = 1;j <= n;j++){
			while(cnt--){
				c += a[j];
				d = a[j];
			}
			if(c > d*2) ans++;
		} 
		cnt++;
	}
	cout << ans;
	return 0;
}
