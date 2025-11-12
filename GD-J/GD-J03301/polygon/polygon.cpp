#include<bits/stdc++.h>
using namespace std;

int ways[25000005],n,maxhe,a[5005],f[5005],
bef[25000005];

ifstream fin("polygon.in");
ofstream fout("ploygon.out");

int main(){
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=a[i]+1;j<=maxhe;j++){
			f[i]+=ways[j];
			f[i]%=998244353;
		}
		maxhe+=a[i];
		for(int j=1;j<=maxhe;j++){
			ways[j+a[i]]+=bef[j];
		}ways[a[i]]=bef[a[i]]+1;
		for(int j=1;j<=maxhe;j++){
			bef[j]=ways[j];
		}
	}
	fout<<f[n];
	fin.close();
	fout.close();
}
/*

5
2 3 1 5 4

5
2 2 3 8 10

*/
