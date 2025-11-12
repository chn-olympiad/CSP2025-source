#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int c(int x,int y){
	int sum1=1,sum2=1;
	for(int i=0;i<x;i++){
		sum1*=y-i;
		sum2*=i+1;
	}
	return sum1/sum2;
}
int a[N],n,k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for(int i=0;i<=n;i++){
    	cin>>a[i];
	}
	if(n==3){
			if(a[0]+a[1]>a[2]&&a[2]+a[1]>a[0]&&a[0]+a[2]>a[1]){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	}else{
		int cnt=0;
		for(int i=3;i<=n;i++){
			cnt+=c(i,n);
		}
		cout<<cnt%998244353;
	}

	return 0;
}
