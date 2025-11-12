#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum;
long long abc(long long ma,long long s,long long i,long long k,bool b){
	if(i<=n){
		if(s>ma*2 && k>=3 && b)sum++;
		abc(ma,s,i+1,k,false);
		abc(max(ma,a[i]),s+a[i],i+1,k+1,true);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(long long i=0;i<n;i++)cin>>a[i];
	abc(0,0,0,0,true);
	cout<<sum%998244353;
 return 0;
}
