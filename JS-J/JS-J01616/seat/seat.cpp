#include<bits/stdc++.h>
std::ifstream("seat.in");
std::ofstream("seat.out");
int a[101];
int main(){
	int n,m,x,id,iid;
	fin>>n>>m;
	for(int i=1;i<=n*m;i++){
		fin>>a[i];
	}
	x=a[1];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			id=i;
			iid=i
		}
	}
	id/=n;
	if(id%2==0){
		fout<<iid%n<<' '<<id;
	}
	else{
		fout<<n-iid%n<<' '<<id;
	}
	return 0;
}
