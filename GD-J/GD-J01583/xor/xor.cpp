#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000000];
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) t=0;
	}
	if(t==1&&k==0) fout<<n/2;
	else{
		int sum0=0;
		int sum1=0;
		int num1=0;
		for(int i=1;i<=n;i++){
				if(a[i]==0) sum0++;
				if(a[i]==1) sum1++;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					num1++;
					i++;
				}
			}
			fout<<sum0+num1;
		}
		if(k==1){
			fout<<sum1;
		}
	}
	return 0;
}
