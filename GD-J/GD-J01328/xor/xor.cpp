#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500001];
long long vis[500001];
long long yh(long long x,long long y){
	return x^y;
}
bool check(long long x){
	long long m=n;
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			x--;
			vis[i]=1;
		}
	}
	long long j=2;
	while(m>0){
		while(vis[j]!=1){
		    a[j]=yh(a[j],a[j-1]);
		    if(a[j]==k){
		    	x--;
		    	break;
			}else{
				continue;
			}
			j++;
			m--;
	    }
	    m--;
	}
	if(x>0){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1;
	long long r=500001;
	while(l<r){
		long long mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
