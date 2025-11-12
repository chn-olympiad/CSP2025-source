#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
long long cnt,cn;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		cn=a[i];
		for(int j=i+1;j<=n;j++){
			cn^=a[j];
			if(cn==k)cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
