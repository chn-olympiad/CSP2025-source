#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	
	long long n,m,a[20000],x = 0,ansn,ansm,ansx;
	fin >> n >> m;
	for(long long i = 1; i <= n*m; i++){
		fin >> a[i];
		if(i == 1) x = a[i];
	}
	sort(a+1,a+n*m+1);
	for(long long i = n*m,l = 1; i >= 1; i--,l++){
		if(x == a[i]){
			ansx = l;
			break;
		}
	}
	if(ansx % n == 0){
		ansm = ansx / n;
		if(ansm % 2 == 0){
			ansn = 1;
		}
		else ansn = n;
	}
	else{
		ansm = ansx / n +1;
		if(ansm %2 == 0){
			ansn = n-(ansx % n)+1;
		}
		else{
			ansn = ansx % n;
		}
	}
	fout << ansm << " " << ansn;
	
	fin.close();
	fout.close();
	return 0; 
}
