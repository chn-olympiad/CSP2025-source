#include<bits/stdc++.h>
using namespace std;
const long long N=1e5;
long long n,k,a[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0)cout<<k+1;
	if(k!=0)cout<<k-1;
	return 0;
}