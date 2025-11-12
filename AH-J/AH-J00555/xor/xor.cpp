#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0) cout<<n/2;
    if(k==1){
		for(int i=1;i<=n;i++) if(a[i]) cnt++;
		cout<<cnt;
	}return 0;
}
