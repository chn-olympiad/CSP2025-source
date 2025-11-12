#include<bits/stdc++.h>
using namespace std;
int n;
#define ll long long
ll k;
const int N=5e5+10;
ll a[N];
int g[N];
int vis[N];
int tol=1;
int cnt0=0,cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
	}
	if(cnt1==n){
		if(k==1){
			cout<<n;
			return 0;
		}else if(k==0){
			cout<<n/2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(cnt0+cnt1==n){
		if(k==1){
			cout<<cnt1;
			return 0;
		}else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1){
					ans++,i+=2;
				}
			}
			cout<<ans;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				cnt++;
				vis[i]=1;
			}
		}
		ll res=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1) continue;
			res=res^a[i];
			if(res==k){
				cnt++;
				res=0;
			}
		}
		cout<<cnt;
	}
	return 0;
}
