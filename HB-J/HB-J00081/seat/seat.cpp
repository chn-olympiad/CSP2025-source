#include<bits/stdc++.h>
using namespace std;
int a[105];
int c=0;
bool cmp(int x,int y){
	return y<x;
	}
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=n*m;i++){
		fin>>a[i];
		if(i==1){
			c=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=n;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			int z=1;
			for(int i=x;i<=y;i++){
				if(a[i]==c){
					fout<<j<<" "<<z;
					return 0;
					}
				z++;
				}
			x=y+1;
			y=y+n;
			}
		if(j%2==0){
			int p=1;
			for(int i=x;i<=y;i++){
				if(a[i]==c){
					fout<<j<<" "<<n-p+1;
					return 0;
				}
				p++;
				}
			x=y+1;
			y=y+n;
			}
	}


	return 0;
	}
