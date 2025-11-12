#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n,k,h=0;
	fin>>n>>k;
	int a[n+1];
	int s[n*n][2]={0};
	fin>>a[1];
	for(int i=2;i<=n;i+=1){
		fin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(i==k){
			s[h][0]=i;s[h][1]=i;
			h++;
		}
		for(int j=1;j+i<=n;j+=1)
		if((a[i]^a[i+j])==k){
			s[h][0]=i;s[h][1]=i+j;
			h++;
		}
	}
	int j,x=1,mx=1;
	for(int i=0;i<h;i+=1){
		j=1;k=i;x=1;
		while(s[k][1]<s[k+j][0]){
			k=k+j;x++;
		}
		mx=max(mx,x);
	}
	fout<<n;
	return 0;
}

