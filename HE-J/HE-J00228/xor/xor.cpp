#include<bits/stdc++.h>
using namespace std;
long long c(long t){
	int l=1;
	for(int i=1;i<=t;i++){
		l*=2;
	}
	return l;
}
long long xo(long x,long y){
	long long m=0;
	long long s=1;
	while(x||y){
		int flag=0;
		if((x%2==1&&y%2==0)||(x%2==0&&y%2==1))flag=1;
		m+=flag*c(s); 
		s++;
	}
	return m;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[50000000],s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long d=a[i];
		for(int j=i;j<=n;j++){
			 if(xo(d,a[j])==k){
			 	i=j+1;
			 	s++;
			 	break;
			 }
		}
	}
	cout<<s;
	return 0;
}
