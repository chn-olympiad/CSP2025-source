#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],sum[N];
int n,k,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=1,r=1;l<=n;r++){
		if(r==n){
			while(l<=n){
				if((sum[r]^sum[l-1])==k){
					ans++;
//					cout<<l<<" "<<r<<"\n";
					l=r+1;
				}
				l++;
			}
			break;
		}
		if((sum[r]^sum[l-1])==k){
			ans++;
//			cout<<l<<" "<<r<<"\n";
			l=r+1;
		}
	}
	cout<<ans;
	return 0;
}
