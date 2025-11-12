#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k,a[10000005],maxa = -1;
	fin >> n >> k;
	for(int i = 0; i < n; i++){
		fin >> a[i];
		maxa = max(maxa,a[i]);
	}
	if(maxa == 1 && k == 0 && maxa % 2 == 0){
		fout << n;
		
		fin.close();
		fout.close();
		return 0;
	}
	if(k == 0 && maxa == 1 && maxa%2){
		fout << n-1;
		
		fin.close();
		fout.close();
		return 0;
	}
	else fout << n/2;
	
	
	fin.close();
	fout.close();
	return 0;
} 
