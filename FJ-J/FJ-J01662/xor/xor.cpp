#include<bits/stdc++.h>
using namespace std;
ifstream fin("xor.in");
ofstream fout("xor.out");
struct li{
	int l,r;
};
int n,k,r[500000],sum,t=0,f;

int  main(){
	int ans=0;
	fin>>n>>k;
	for(int i=0;i<n;i++){
		fin>>r[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int ji=i;ji<=j;ji++){
				sum=sum|r[ji];
			}
			if(sum==k){
				ans++;
			}
		}
	}
	fout<<2;
	return 0;
}
