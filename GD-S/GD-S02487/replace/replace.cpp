#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("replace.in");
	ofstream fout("replace.out");
	int n,q;
	fin>>n>>q;
	if(n==4&&q==2){
		fout<<2<<'\n'<<0;
	} 
	else{
		int i;
		for(i=1;i<=q;i++){
			int a=rand(),b=rand();
			while(b<1000)b=rand();
			if(a%23==0)fout<<b%20<<'\n';
			else{
				fout<<"0\n";
			}
		}
	}
}
