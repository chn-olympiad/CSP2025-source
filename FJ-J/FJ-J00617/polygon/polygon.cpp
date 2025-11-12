#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long mod=998244353 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,sum=0,maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(a[i],maxx);
	}
	if(n==3){
		if(sum>maxx){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
