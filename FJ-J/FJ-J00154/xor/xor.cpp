#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],cnt=0,cntt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1) cnt++;
		if(a[i]==0) cntt++;
	}
	if(k==0){
		if(cnt==n){
			if(cnt%2==1) cout<<0;
			else cout<<n/2;
		}
		else{
			if(cnt%2==1) cout<<0;
			else cout<<cntt+cnt/2;
		}
	}
	return 0;
} 
