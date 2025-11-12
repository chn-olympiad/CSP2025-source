#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
long long ar[N];
long long n,k,m,h,l,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>ar[i];
	}
	long long j = ar[1];
	for(int i = 1;i<=n*m;i++){
		if(j<=ar[i]){
			ans++;
		}
	}
	if(ans%n == 0){
		h  = ans/n;
	}else{
		h = ans/n+1;
	}
	long long kk = ans%(2*n);
	if(kk == 0||kk == 1){
		l = 1;
	}else if(kk<=n){
		l = kk;
	}else{
		l = 2*n+1-kk;
	}
	cout<<h<<" "<<l;
	return 0;
} 
