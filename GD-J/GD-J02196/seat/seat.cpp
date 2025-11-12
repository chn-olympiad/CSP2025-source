#include<bits/stdc++.h>
using namespace std;
int a[101];
bool s[101]={0};
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m,x;
	fin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		fin>>a[i];
		s[101-a[i]]=1;
	}x=0,m=101-a[1];
	for(int i=1;i<=m;i++){
		x+=s[i];
	}
	int c=((x+n-1)/n);
	int r=(x-1)%n+1;
	if(((x-1)/n)%2){
		r=n+1-r;
	}
	fout<<c<<" "<<r;
	return 0;
}

