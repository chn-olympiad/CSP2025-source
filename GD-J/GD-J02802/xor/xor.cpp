#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long n,k,a[500005],ans=0,tmp=0;
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			tmp=0;
			continue;
		}
		tmp^=a[i];
		if(tmp==k){
			ans++;
			tmp=0;
		} 
	}
	cout<<ans;
	return 0;
}
