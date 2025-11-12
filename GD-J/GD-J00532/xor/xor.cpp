#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5e5+10;
ll a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	ll pree=0;
	ll ans=0;
	for(ll i=1;i<=n;i++)scanf("%d",&a[i]);
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){

			if(i==j&&a[i]==k){
				ans++;
				i++;
				//j++;
			}
			else{
				pree=a[i];
				for(int z=i+1;z<=j;z++){
					if((pree xor a[z])==k&&pree!=0&&a[z]!=0){
						ans++;
						i=z+1;
						j=i;
						break;
					}
					else{
						pree=(pree xor a[z]);
					}
				}			
			}

		}
	}
	cout<<ans;
	
	return 0;
}
