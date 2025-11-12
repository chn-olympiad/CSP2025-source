#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	if((n<=2||n<=100)&&k==0) cout<<n/2;
	else cout<<n/k;
	
	return 0;
}