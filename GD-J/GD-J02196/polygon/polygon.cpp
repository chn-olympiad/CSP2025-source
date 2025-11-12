#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	int n;
	fin>>n;
	int a[n+1]={0},b[n+1]={0},s=0;
	for(int i=1;i<=n;i+=1){
		fin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i+=1)
		b[i]=b[i-1]+a[i];
	for(int i=n;i>=3;i--){
		for(int j=0;j<i;j++){
			if((b[j-1]-b[i])>a[j])s++;
		}
	}
	fout<<s;
	return 0;
}

