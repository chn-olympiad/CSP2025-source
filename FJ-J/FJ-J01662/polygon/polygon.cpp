#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
ifstream fin("polygon.in");
ofstream fout("polygon.out");
long long c(int i,int l,long long sum){
	int cr=0;
	for(int j=l;j<n;j++){
		if(i==1){
			if(sum+a[j]>a[j]*2){
				cr+= 1;
			}
		}
		else cr+=c(i-1,j+1,sum+a[j]);
	}
	return cr;
}
int main(){
	long long count=0;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<n;i++){
		count+=c(i,0,0);
	}
	count+=1;
	fout<<count % 998244353;
	return 0;
}
