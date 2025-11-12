#include<bits/stdc++.h>
using namespace std;

long long a[500010];
long long n,k;

int func(int x,int y){
	if(x==0)
		return a[y];
	else
		return (a[y])^(func(x-1,y-1));
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int cnt=0;
	int f=0;
	for(int i=0;i<n;i++){
		if(func(f,i)==k){
			cnt++;
			f=0;	
		}
		else
			f++;
	}
	cout<<cnt;
	
	return 0;
}
