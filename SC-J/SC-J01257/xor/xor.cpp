#include <bits/stdc++.h>
using namespace std;
int a[500010],n,k,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}