#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M=5e3+5;
ll n,a[M],temp;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3) cout<<0;
	else {
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			temp=temp+a[i];
		}
		if(temp>(a[n]*2)) cout<<1;
		else cout<<0;
	} 
	return 0;
}
