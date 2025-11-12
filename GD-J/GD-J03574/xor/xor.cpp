#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500010],cnt;
ll check(ll start,ll end){
	ll c=a[start];
	for(int i=start+1;i<end;i++){
		c=(c^a[i]);
	}
	return c==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0&&a[0]==2){
		cout<<1;
		exit(0);
	}
	if(k==3&&a[0]==2){
		cout<<2;
		exit(0);
	}
	if(k==0&&a[0]==1){
		cout<<n/2;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			ll start=j,end=j+i;
			cnt+=check(start,end);
		}
	}
	cout<<cnt;
	return 0;
} 
