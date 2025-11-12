#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k,cnt = 0,x = 0,j = 0;
	cin >> n>>k;
	int a[n],sum[n];
	int b[n];
	sum[0] = 0;
	for(int i = 0;i< n;i++){
		cin >> a[i];
		sum[i+1] = sum[i] + a[i];
		if(a[i]<= k) b[i] = 1;
		if(k == 0 && a[i] == 0){
			cnt++;
		}
	} 
	if(k == 0){
		cout << cnt;
		return 0;
	}
	cnt = 0;
	for(int i = 0;i< n;i++){
		if(b[i] == 1 && sum[i+1] - sum[j+1] >= k) cnt++;
	}
	cout << cnt;
	return 0;
}
