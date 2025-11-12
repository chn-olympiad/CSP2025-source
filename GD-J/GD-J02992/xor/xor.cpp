#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,m=1<<20,M=m+10;
ll n,k,x,sum,t[M],r,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<m;i++) t[i]=-1;
	for(ll i=1;i<=n;i++){
		cin>>x;
		sum^=x;
		if(t[sum^k]>=r) r=i,cnt++;
		t[sum]=i;
	}
	cout<<cnt;
	return 0;
}
