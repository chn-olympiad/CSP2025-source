#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int arr[100005];
int brr[100005][100005];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int u = n * m;
	cin >> arr[1];
	int num1 = arr[1];
	for(int i = 2;i <= u;i++){
		cin >> arr[i];
	}
	sort(arr + 1,arr+ u,cmp);
	int num = 1;
	int cnt = 1;
	for(int i = 1;i <= n;i++){
		if(num % 2 == 1){
			for(int j = 1;j <= m;j++){
				if(arr[cnt] == num1){
					cout << i << ' ' << j;
					return 0;
				}cnt++;
			}
		}else{
			for(int k = m;k > 0;k--){
				if(arr[cnt] == num1){
					cout << i << ' ' << k;
					return 0;
				}
				cnt++;			
			}
		}
	}
	return 0;
}
