#include<cstdio>
#include<iostream>
#include<fstream>
std::ifstream fin("seat.in");
std::ofstream fout("seat.out");
int main(){
	int a,n,m;
	fin>>n>>m;
	fin>>a;
	
	int scoreb;
	int k=1;
	for(int i=1;i<n*m;i++){
		fin>>scoreb;
		if(scoreb>a)
			k++;
		}
		
	int ans1=(k+n-1)/n;
	int ans2=0;
		
	if(ans1%2)
		ans2=((k-1)%n)+1;
	else
		ans2=n-(k%n)+1;
		
	fout<<ans1<<" "<<ans2;
}
		
		
	
