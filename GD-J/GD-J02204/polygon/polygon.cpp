#include<bits/stdc++.h>;
using namespace std;
int n;
int a[5010],dp[5010],c[5010];
bool b[5010];
int sum;
bool cmp(int e,int t){
	if(e > t){
		return 1;
	}
	return 0;
}
int main(){
	int cnt = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		c[i] = a[i];
		cnt = cnt + a[i];
	} 
	sort(a,a + n,cmp);
	sort(c,c + n);
	int ma = a[0];
	cnt = cnt - a[0];
	for(int i = 0;i < n;i++){
		int k = i;
		int p = 1;
		while(cnt <= 2 * ma || k < n){
			int d = p;
			if(d % 2){
				cnt = c[k] + cnt;
			}
			d = d / 2;
			p++;
			k++;
		}
		if(cnt > 2 * ma){
			sum = sum + (pow(2,n - i) - p);
		}
	}
	cout << sum;
	return 0;
}
