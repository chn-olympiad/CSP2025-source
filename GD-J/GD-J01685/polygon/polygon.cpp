#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int x[1000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1,cmp);
	if(x[1]<x[2]+x[3]){
		cout<<"1";
		
	}else{
		cout<<"0";
	}
	return 0;
}
