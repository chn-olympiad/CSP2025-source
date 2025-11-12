#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c(long long a,long long b){
	long long ans=1; 
	for(int i=1;i<=a;i++){
		ans=ans*(b-i+1)%998244353;
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cout<<c(m,n);                                     
	return 0;	
}

