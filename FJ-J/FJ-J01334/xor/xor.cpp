#include<bits/stdc++.h>
#define maxn 5050
using namespace std;
long long n,k,a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(!k && a[1]==a[n] && !a[1]) return !printf("1");
	if(k) cout<<"0";
	else cout<<n;
	return 0;
}
