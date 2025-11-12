#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,m[200007],ans;
bool flag = true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1;i<=n;i++){
		cin>>m[i];if(m[i]==0)flag = false;
	}
	if(flag){
		if(k==0)cout<<n/2;
		else cout<<n;
	}
	else{
	    if(k==0){
	    	for(ll i = 1;i<=n;i++){
		        if(m[i]==0)ans++;
		        if(m[i]==1&&m[i-1]==1)ans++; 
	        }
	        cout<<ans;
		}
		else{
			for(ll i = 1;i<=n;i++){
		        if(m[i]==1)ans++; 
	        }
	        cout<<ans;
		}
	}
	return 0;
}
