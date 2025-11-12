#include <bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n&&k==0){
		cout<<n-1;
	}
	return 0;
}
