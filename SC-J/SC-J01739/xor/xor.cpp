#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(!(n&1))
    cout<<n/2;
	else cout<<0;
	return 0;
}