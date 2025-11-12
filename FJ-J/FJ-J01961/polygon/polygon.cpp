#include<bits/stdc++.h>
#define modd 998244353
using namespace std;
typedef long long ll;
ll n,a[5050],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans/a[n]*a[(ll)ceil((double)n/2)];
	return 0;
}
