#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int main(){
	/*
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);*/
	int n,m,x[N],s=0;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>x[i];
	}
	for(int i=1;i<=b;i++){
		int a=x[1];
		if(a<x[i+1]){
			s++;
		}
	}
	int q=s%n+2;
	cout<<q;
	cout<<" ";
	if(q%2!=0){
		cout<<(s+1)/q;
	}
	else{
		cout<<s%n;
	}
	return 0;
} 
