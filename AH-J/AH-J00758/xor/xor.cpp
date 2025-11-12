#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,k,a[N],sum[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sum[r]^sum[l-1] ) ==k && l<=r){
				cnt++;
				l=r+1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
