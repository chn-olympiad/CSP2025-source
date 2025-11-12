#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");	
	int n;
	fin>>n;
	int a[n];
	int N=n;
	if(n<3){
		fout<<0; 
		return 0;
	}
	for(int i=0;i<n;i++){
		fin>>a[n];
	} 
	int t=1;
	int now[500]={0};
	now[0]=1;
	for(int i=1;i<=500;i++){
		now[i]=now[i-1]+i+1;
	}
	int ans=0;
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<=i;j++){
			ans+=now[j];
		}
	}
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
}
