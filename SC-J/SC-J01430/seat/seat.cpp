#include<fstream>
#include<iostream>
#include<string> 
using namespace std;
int main()
{
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m;
	int c,r;
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a[n*m-1],a1;
			fin>>a1>>a[n*m-1];
			if(max(a[n*m-1],a1)==a1){
				c=1, r=1;	
			}else if(min(a[n*m-1],a1)==a1){
			    c=m, r=n;
			}
		}
	} 
	fout<<c<<r;
	fin.close();
	fout.close();
	return 0;
}