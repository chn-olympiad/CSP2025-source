#include<bits/stdc++.h>
using namespace std;
int a,sz[5100],da;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>sz[i];
	}
	int jl;
	for(int j=1;j<=a;j++){
		for(int i=1;i<=a;i++){
			if(sz[i]>sz[i+1]){
				jl=sz[i];
				sz[i]=sz[i+1];
				sz[i+1]=jl;
			}
		}
	}
	for(int j=1;j<=a;j++){
		int jls[5100];
		for(int i=j;i<=a;i++){
			jls[j]=jls[j-1]+sz[i];
			if(jls[j]>sz[i]*2){
				da++;
			}
		}
	}
	cout<<da%998244353;
	return 0;
} 
