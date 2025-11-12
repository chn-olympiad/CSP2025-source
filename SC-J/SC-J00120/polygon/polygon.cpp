#include<bits/stdc++.h>

using namespace std;
int n,a[5001],b[5001],sum=0,b1;
void pai(int as,int s){
	for(int i=as+1;i<=n-1;i++){
		if(s+a[i]>b1){
			sum++;
			sum%=998244353;
		}
		pai(i,s+a[i]);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	while(n){
		b1=a[n];
		for(int i=1;i<=n-2;i++){
			pai(i,a[i]);
		}n--;
	}cout<<sum;
	return 0;
} 