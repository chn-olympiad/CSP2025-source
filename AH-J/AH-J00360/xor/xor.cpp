#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],b[500010];
bool c[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,cnt=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){ 
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}for(ll r=1;r<=n;r++){
		for(ll l=0;l<r;l++){
			if(ll(b[r]^b[l])==k){
				bool ok=0;
				for(ll i=l;i<r;i++){
					if(c[i]){
						ok=1;
						break;
					}else{
						c[i]=1;
					}
				}if(!ok){
					cnt++;
				}
			}
		}
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
