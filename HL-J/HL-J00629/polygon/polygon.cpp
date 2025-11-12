#include<bits/stdc++.h>
using namespace std;
int a[10010],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[i]<a[j]){
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}//ÅÅÐò
	cout << a[1]+a[2];
	return 0;
} 
