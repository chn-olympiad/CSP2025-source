#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],t[N],k,ans,l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=t[i-1]^a[i];
		for(int j=l;j<i;j++)if((t[i]^t[j])==k){
			ans++;
			l=i;
			break;
		}
	}cout<<ans<<'\n';
	return 0;
}
