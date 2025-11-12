#include<bits/stdc++.h> 
using namespace std;
int num;
int a[100001];

int maxn(int q[],int n){
	int tmax=0;
	for(int i=1;i<=n;i++){
		if(q[i]>tmax)
			tmax=q[i];
	}
}


bool ispolygon(int q[],int n){
	int tmax=maxn(q[],n);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=q[i];
	}
	if(sum>tmax){
		return 1;
	}
	else{
		return 0;
	} 
}

 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	
	return 0;
}