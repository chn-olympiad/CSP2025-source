#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,a[100010],pre[100010],l,r,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			l=i; 
			continue;
		}
		r=i;
		int ll=l;
		while(ll<r){
			if((pre[r]^pre[ll])==k){
				ans++;
				l=r;
				break;
			}
			ll++;
		}
	}
	cout<<ans;
	return 0;
}
