#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k,x,ans=0,l=0,r=0;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=a[i-1]^x;
	}
	while(r<n){
		r++;
		for(int i=l;i<r;i++){
			x=a[i]^a[r];
			if(x==k){
				ans++;
				l=r;
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
