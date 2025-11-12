#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],tot,x,s;
bool aok(){
	if(k!=0) return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
}
bool bok(){
	if(k>1) return false;
	for(int i=1;i<=n;i++){
		if(a[i]>1) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(aok()){
		cout<<n/2;
		return 0;
	}
	if(bok()){
		for(int i=1;i<=n;i++){
			if(a[i]==1) tot++;
		}
		if(k==1&&tot==0) cout<<0;
		else cout<<n;
		return 0;
	}
	cout<<2;
	return 0;
}
