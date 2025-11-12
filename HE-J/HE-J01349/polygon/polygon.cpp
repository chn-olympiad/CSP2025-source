#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	if(n<=3){
		int m = arr[0];
		for(int i = 0;i < n;i++){
			m = max(arr[i],m);
			
		}
		if(n == 1){
			cout << 0;
					}
		else if(n == 2)
		{
			cout << 0;
		}
		
		else  if(n == 3)
		{
			int c =  0;
			int a = arr[0];
			int b = arr[1];int g = arr[2];
			if(a+b+g > 2*m){
				cout << 1;
				}
	else{
		cout << 0;
	}		
			
			
		}
	}
	return 0;
}
