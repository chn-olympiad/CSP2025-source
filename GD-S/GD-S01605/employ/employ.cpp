#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long jc(long long x,long long y){
	long long ans=1;
	for(long long i=y;i<=x;i++){
		ans%=mod;
		ans*=i;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    long long n1=n;
    for(long long i=0;i<n;i++){
    	long long x;
    	cin>>x;
    	if(x==0){
    		n1--;
		}
	}
	if(n1<m){
		cout<<0<<endl;
		return 0;
	}
    cout<<jc(n,n-m+1)%mod;
	return 0;
} 
