#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long jc(long long k){
	int s=1;
	for(long long i=1;i<=k;i++){
		s*=i;
	}
	return s;
}
long long C(long long n,long long m){
	long long fm=jc(m-n)*jc(n);
	long long fz=jc(m);
	return fz/fm;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long long n;
	cin>>n;
	long long ma=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(n<3){
		cout<<0;
		return 0;
	}else{
		if(n==3){
			if((a[1]+a[2]+a[3])>ma){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			long long num=0;
			for(long long i=1;i<=n;i++){
				num+=C(i,n);
			}
			cout<<num%998244353;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 