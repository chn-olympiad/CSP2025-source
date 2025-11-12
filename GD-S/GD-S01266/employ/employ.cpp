#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int mod=998244353;
long long jc(long long x){
	long long t=1;
	for(int i=1;i<=x;i++){
		t*=i;
		t%=mod;
	}
	return (t%mod);
}
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0){
			n--;
		}
	}
	long long n1=1;
	for(int i=1;i<=n;i++){
		n1*=i;
		n1%=mod;
	}
	long long tian=0;
	for(int i=m;i<=n;i++){
		tian+=(n1/(jc(n-i)*jc(i)%mod))%mod;
		tian%=mod;
	}
	cout<<tian
	return 0;
}

 
