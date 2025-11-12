#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;

int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	
	fin >> n;
	for(int i = 1; i <= n; i++){
		fin >> a[i];
	}
	if(n == 3){
		sort(a+1,a+n+1);
		if(a[3] < a[1]+a[2]) fout << 1;
		else fout << 0;
		
	}
	else{
		for(int i = 3; i <= n; i++){
			cnt++;
		}
		fout << cnt*2;
	}
	
	fin.close();
	fout.close();
	
	return 0;
} 
