#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
long long a[5005];
long long n,cnx;
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++){
		for(long long l=1;l<=n;l++){
			long long r=l+i-1;
			if(r>n) break;
			long long ma=-1,sum=0;
			for(long long p=l;p<=r;p++){
				sum+=a[p];
				ma=max(a[p],ma);
			}
			if(sum>(ma*2)) cnx++;
		}
	}
	cout<<cnx%mo;
	return 0;
}
