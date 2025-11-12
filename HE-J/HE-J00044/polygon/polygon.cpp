#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,r;
	int sum=0,maxn=0;
	int sumn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r;
		if(r<=maxn){
			maxn=r;
		}
		sum+=r;
	}
	if(n>=3||sum>maxn*2){
		sumn++;
	}
	cout<<sumn; 
	return 0;
}

