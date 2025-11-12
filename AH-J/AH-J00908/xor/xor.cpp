#include<bits/stdc++.h>
using namespace std;
long long i,k,n,cnt[1000010],a[100010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	cout<<cnt[k];
    return 0;
}
