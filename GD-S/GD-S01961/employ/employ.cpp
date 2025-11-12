#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("employ.in");
	ofstream fout("employ.out");
	int n,m;
	fin>>n>>m;
	string z;
	int c[n],ee=0;
	bool s[n],f=1;
	fin>>z;
	for(int i=0;i<n;i++){
		fin>>c[i];
		if(!c[i])ee++;
	}
	for(int i=0;i<n;i++){
		s[i]=(z[i]=='1');
		if(!s[i])f=0;
	}
	long long k=1;
	if(f&&n-ee>=m){
		for(int i=2;i<=n;i+=1){
			k*=i;
			k%=998244353;}
		fout<<k<<endl;
	}
	else{
		fout<<0<<endl;
	}
	return 0;
}

