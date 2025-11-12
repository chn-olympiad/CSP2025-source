#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}int s=0,c=0;
	for(long long i=1;i<=n;i++){
		s=(a[i]|s)-(a[i]&s);
		if(s==k){
			c++;
			s=0;
		}
	}
	cout<<c;
    return 0;
}

