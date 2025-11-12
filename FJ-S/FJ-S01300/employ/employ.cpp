#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
bool pass[525];
long long c[525];
long long rem[525];
long long j(long long x){
	if(x == 0){
		return 1;
	}
	if(rem[x] == 0){
		x %= mod;
		rem[x] = j(x-1) % mod * x;
	}
	return rem[x];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1; i<= n; i++){
		cin>>pass[i];
	}
	for(int i = 1; i<= n; i++){
		cin>>c[i];
		
	}
//	sort(c+1,c+n+1);
//	do{
//		
//	}while(prev_prmunitation(c+1,c+n+1));
	cout<<j(n)<<endl;
	return 0;
}
