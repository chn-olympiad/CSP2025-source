#include<bits/stdc++.h>
using namespace std;
long long a[10000],s=0,n;
long long p(long long key,long long sum,long long step){
	for(long long i=key;i<n;i++){
		if(step>=3){
			if(sum+a[i]>a[i]*2)s=(s+1)%998244353; 
		}
		p(i+1,sum+a[i],step+1);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	p(0,0,1);
	cout<<s;
	return 0;
}
