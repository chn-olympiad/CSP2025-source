#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	long long maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn =max(maxn,a[i]);
	}
    if(n==3){
    	if(a[1]+a[2]+a[3]>maxn*2) cout<<1;
	}
	else if(maxn==1&&n>=3) {
	long long p= (n-1)*(n-2)/2;
	cout<<p%998244353;
    }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
	
