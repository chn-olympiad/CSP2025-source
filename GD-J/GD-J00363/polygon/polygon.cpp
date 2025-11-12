#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int sum=0,maxn;
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	} 
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else              cout<<0;
		return 0;	
	}else if(flag==1){
		cout<<n;
		return 0;
	}else{
		cout<<"这题目诗人？？？？？？"; 
	}
	return 0;
} 
