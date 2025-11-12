#include<bits/stdc++.h>
using namespace std;

int n,m,c,r,xiaor;
int a[105];

ifstream fin("seat.in");
ofstream fout("seat.out");

int main(){
	fin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==xiaor){
			c=i/n+1;
			r=i%n;
			if(r==0){
				c--;
				r=n;
			}
			if(c%2==0){
				r=n-r+1;
			}
			break;
		}
	}
	fout<<c<<" "<<r;
	fin.close();
	fout.close();
}
