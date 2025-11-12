#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+7;
ll n,k;
ll a[maxn];
ll t[maxn],ctt;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(!f&&k==0){
		cout<<n/2;
		return 0;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			t[i]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]!=INT_MAX){
			ll p=a[i];
			for(int j=i+1;t[j]!=INT_MAX&&j<=n;j++){
				p=p^a[j];
			//cout<<p<<" "<<j<<endl;
				if(p==k){
					cnt++;
					i=j;
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
//4 0
// 2 1 0 3
