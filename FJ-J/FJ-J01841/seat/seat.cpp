#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m;
	fin>>n>>m;
	int R;
	fin>>R;
	int count=0;
	for(int i=1;i<n*m;i++){
		int si;
		cin>>si;
		if(si>R)
		count++;
	}
	int c,r;
	c=(count+n)/n;
	r=count%n+1;
	if(c%2==0){
		r=n-r+1;
	}
	fout<<c<<" "<<r;
	fin.close();
	fout.close();
	return 0;
}
