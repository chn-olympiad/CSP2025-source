#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	ll mx=-1,cnt1=0,cnt0=0;
	bool all1=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		all1&=(a[i]==1);
		if(a[i]==1)cnt1++;
		else if(a[i]==0)cnt0++;
	}
	//printf("\n mx:%lld  all1:%d  1:%lld  0:%lld \n",mx,all1,cnt1,cnt0);
	if(all1){
		if(k==1)ans=n;
		else if(k==0)ans=n/2;
		else ans=0;
	}else if(mx<=1){
		if(k==1)ans=cnt1;
		else if(k==0){
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]&a[i+1]){
					cnt++;
					a[i]=a[i+1]=0;
				}
			}
			ans=cnt0+cnt;
		}
	}else{
		
	}
	cout<<ans;
	return 0;
}
