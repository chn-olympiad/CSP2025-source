#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200009];
int maxx = -1;
bool teshu= 1;
int sum = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
		if(a[i] == 0){
			teshu = 0;
		}
	}
	if(maxx == 1 && teshu){
		cout << n / 2;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			sum++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != k && a[i+1] != k){
			sum++;
			i++;
		}
	}
	cout << sum;
	return 0;
}
