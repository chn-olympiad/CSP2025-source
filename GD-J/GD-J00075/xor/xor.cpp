#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+10;
int n,k,a[maxn];
bool b=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=(b&&(a[i]==1));
	}
	if(!k&&b)cout<<n/2;
	return 0;
}
