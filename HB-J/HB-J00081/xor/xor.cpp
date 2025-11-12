#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k,cnt=0;
	fin>>n>>k;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		if(a[i]==0)cnt++;
		}
	fout<<cnt;
	
	return 0;
	}


