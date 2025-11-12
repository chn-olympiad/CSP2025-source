#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,ans;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k<=1){
		cout<<k;
		return 0;
	}
	ans=a[1];
	for(int i=1;i<=n;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
