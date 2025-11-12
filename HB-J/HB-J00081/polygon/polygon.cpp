#include<bits/stdc++.h>
using namespace std;
int a[5005];
int mian(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n,cnt=0,mmax=0;
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];	
		cnt+=a[i];	
		mmax=max(a[i],mmax);
		}
	if(cnt>mmax+mmax)fout<<1;
	else fout<<0;
	
	
	return 0;
	}
