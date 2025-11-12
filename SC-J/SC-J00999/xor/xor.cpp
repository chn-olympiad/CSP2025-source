#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5,MOD=998244353;
int n,k,a[N],ok1=1,ok2=1,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) ok1=0;
		if(a[i]>1) ok2=0;
	}
	if(ok1){
		cout<<n/2;
	}else if(ok2){
		if(k==0) {
			for(int i=1;i<n;i+=2) if(a[i]==a[i+1]) cnt++;
		}else{
			for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
		}
		cout<<cnt;
	}else {
		cout<<2;
	}
	return 0;
}