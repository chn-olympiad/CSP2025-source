#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long sumn=0;
int c(int x,int y){
	long long sum1=1,sum2=1;
	for(int i=2;i<=y;i++){
		sum1*=i;
	}
	int a=x-y+1;
	for(int i=x;i>=a;i--){
		sum2*=i;
	}
	return sum2/sum1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1 || n==2){
		cout<<0;
	}
	else if(n==3){
		cout<<1;
	}
	else{
		for(int i=3;i<=n;i++){
			sumn+=c(n,i);	
		}
		cout<<sumn%998244353;
	}
	return 0;
} 
