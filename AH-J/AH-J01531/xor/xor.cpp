#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	LL cnt=0;
	for(LL i=1;i<=n;i++){
		for(LL j=1;j<=n;j++){
			if(a[i]==a[j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	
	return 0;
}
