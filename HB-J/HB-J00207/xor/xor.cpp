#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]==0) cnt++;
	cout<<cnt;
	return 0;
}
