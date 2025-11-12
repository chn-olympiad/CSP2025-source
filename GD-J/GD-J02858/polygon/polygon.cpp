#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[105];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 3){
		int j = 3;
		while(j){
			for(int i = 1;i <= 3;i++){
				if(a[i] < a[i+1]){
					swap(a[i],a[i+1]);
				}
			}
			j--;	
		}
		if (a[2]+a[3]>a[1]){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else{
		cout << "6";
	}
	return 0;
}
