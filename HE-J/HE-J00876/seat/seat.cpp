#include<bits/stdc++.h>
using namespace std;

int m, n;
int a[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;	//ÐÐ£¬ÁÐ 
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	int t=a[1];
	sort(a, a+n*m+1);
	for(int i=1; i<=n*m; i++){
		if(a[i] == t){
			t = i;
			break;
		}
	}
	
	t = n*m - t + 1;
	
	int j;
	if(t % n == 0){
		j = t/n;
	}else{
		j = t/n + 1;
	}
	
	int i = t % n;		//ÐÐ
	if(i == 0){
		if(j % 2 == 0){
			i = 1;
		}else{
			i = n;
		}
	}
	if(j % 2 == 0){
		i = n-i+1; 
	}
	
	cout << j << " " << i;
	
	return 0;
}
