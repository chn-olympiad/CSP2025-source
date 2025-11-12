#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long l=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int n=a[1],m=a[2],f=a[3];
		if((n+m)>f&&(n-m)>f) cout<<1;
		else cout<<0;
		return 0;
	} 
	for(int i=3;i<=n;i++){
		long long k=1;
		int b=i;
		while(b>0){
			k*=(n-b+1);
			k%=998244353;
			b--;
		}
		l+=b;
		l%=998244353;
	}
}
