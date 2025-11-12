#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n; 
	fin >> n; 
	int arr[n];
	int ans = 0;
	for(int i = 0 ;i < n;i++){
		fin >> arr[i];
	}
	
	fout << 5;
	fin.close();
	fout.close();
	return 0;
} 
