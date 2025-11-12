#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int ansm,ansn,n,m;
	fin>>n>>m;
	int a[m][n];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) fin>>a[i][j];//ok
	

	
	int x=a[0][0];
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) for(int k=i;k<m;k++) for(int t=j+1;t<m;t++) if(a[i][j]<a[k][t]) swap(a[i][j],a[k][t]);//no
	

	
	
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(a[i][j]==x){
		ansm=i+1;ansn=j+1;i=m;
	}
	
	
	fout<<ansm<<" "<<ansn;
	
	
	fin.close();
	fout.close();
} 
