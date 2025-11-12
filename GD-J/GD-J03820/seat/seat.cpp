#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int change(int a,int b){
	a = a+b;
	b = a-b;
	a = a-b;
}
int main(){
	int n,m;
	cin >> n >> m;
	int num[n*m];
	int a[n][m];
	for(int i = 0;i < n*m;i++){
		cin >> num[i];
	} 
	for(int i = 0;i < n*m;i++){
		if(num[i] < num[i+1]){
			change(num[1],num[i+1]);
		}
	} 
	for(int i = 0;i<n*m;i++){
		cout << num[i];
	}
} 

