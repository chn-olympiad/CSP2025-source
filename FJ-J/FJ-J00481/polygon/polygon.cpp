#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
ll n,a[N],i,j,z;
int main(){
	freopen("polygon","w",stdin);
	freopen("polygon","r",stdout); 
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); 
	cout<<a[n-1]+a[n]<<endl;
	return 0;
}
