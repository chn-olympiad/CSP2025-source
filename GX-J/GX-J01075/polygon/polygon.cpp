#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],cnt = 0;

bool cmp(int x ,int y){
	return x > y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int k = j;k <= n;k++){
				int sum = a[i] + a[j] + a[k];
				if(a[1] * 2 < sum && i != j && j != k && k != i){
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
