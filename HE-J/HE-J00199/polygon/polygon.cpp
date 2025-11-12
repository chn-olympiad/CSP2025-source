#include<bits/stdc++.h>
using namespace std;
long long int n,a[10000],ss=0,x[10000];
int f(long long int i,long long int s,long long int s2){
	if(i==1){
		for(;s<=n-i;s++){
			x[i]=a[s];
			long long int z=0;
			for(int j=1;j<=s2;j++){
				z+=x[j];
			}
			if(z>2*x[1]){
				ss=(ss+1)%998244353;
			}
		}
	}
	else{
		for(;s<=n-i;s++){
			x[i]=a[s];
			f(i-1,s+1,s2);
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a-1,a+n);
	for(int i=3;i<=n;i++){
		f(i,0,i);
	}
	cout<<ss;
	return 0;
}
