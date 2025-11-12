#include <bits/stdc++.h>
using namespace std;
//bro this is a triangle
int poly(int a[],int x){
	int cnt = 0;
	while(cnt != x -1){
		cnt = 0;
		for(int i = 0; i < x - 1; i++){
			if(a[i] < a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		for(int i = 0; i < x-1; i++){
			if(a[i] >= a[i+1]){
				cnt++;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < x; i++){
		sum += a[i];
	}
	if(sum > a[0] * 2){
		
		for(int i = 0; i < x; i++){
			cout << a[i] << " ";
		}
		return 1;
	}else{
		return 0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; 
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = 0;
	}
	int sum = 0;
	for(int i = 0; i < n - 2; i++){
		for(int j = i+1; j < n -1; j++){
			for(int k = j+1; k < n; k++){
				if(a[i]+a[j]+a[k] > max(a[i],max(a[j],a[k]))* 2){
					sum++;
					//cout << a[i] << a[j] << a[k] << endl;
				} 
			}
		}
	}
	/*for(int i = 3 ; i <= n; i++){
	//	cout << i << "	";
		for(int j = 0; j < n - i + 1; j++){
			//cout << j << ":";
			for(int k = 0; k < n; k++){
				b[k] = 0;
			}
			for(int k = j; k < j+i; k++){
				b[k] = a[k];
			//	cout << k << " ";
			}
		//	for(int k = 0; k < n; k++){
		//		cout << b[i] << " ";
		//	}
			//cout << "	";
			sum += poly(b,i);
			cout << endl;
		}
	//	cout << endl;
	}*/
	cout << sum;
}
