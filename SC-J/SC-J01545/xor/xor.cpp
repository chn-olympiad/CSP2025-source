#include<bits/stdc++.h>
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define int long long 
using namespace std;
const int maxn=500000+200;
int xo[maxn]; int a[maxn]; int n,k,ki,ans=0;
int z2(int x){if(x>=2)return z2(x/2)+1; else return 0;}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	I AK CSP
	cin>>n>>k; ki=z2(k);
	for(int i=1;i<=n;i++)cin>>a[i];
	xo[n]=a[n];
	for(int i=n-1;i>=0;i--)xo[i]=(xo[i+1]^a[i]);
	int maxi=0; int r=0;
	for(int i=1;i<=n;i++){
		maxi=max(maxi,z2(a[i]));
		if(maxi<ki)continue;
		else {
			for(int j=i;j>r;j--){
				if((xo[j]^xo[i+1])==k){
					maxi=0; ans++; r=i; break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}