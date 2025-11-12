#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500050];
int xpre[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xpre[i]=xpre[i-1]^a[i];
		if(xpre[i]==k)cnt++;
	}
	int p=1;
	for(int i=1;i<=n;i++){
		if(xpre[i]^xpre[p]==k){
			ans++;
			p=i+1;
		}
	}
	cout<<ans;
	return 0;
}
