#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5*5+10;
LL n,k,a[N],b[N],cnt,l,r;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int i=1;
	for(;i<=n;){
		for(int j=i;j<=n;j++){
			LL t=b[j]^b[i-1];
			if(t==k){
				cnt++;
				i=j;
				break;
			}
		}
		i++;
    }
    cout<<cnt;
	return 0;
}
