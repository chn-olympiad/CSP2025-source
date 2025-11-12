#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n,m;
int arr[N]; 

bool cmp(int a, int b){
	return a > b;
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i ++){
		cin >> arr[i];
	}
	int tag = arr[1];
	sort(arr + 1, arr + 1 + n * m, cmp);
//	for (int i = 1; i <= n*m; i ++){
//		cout << arr[i];
//	}
	
	int x=1,y=1;
	for (int i = 1; i <= n*m; i ++){
		if (tag == arr[i]){
			cout << y << ' ' << x;
			break;
		} 
		if (x == 1 && y % 2 == 0 || x == n && y % 2 == 1){
			y ++;
		} else if (y % 2 == 1){
			x ++;
		} else {
			x --;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
