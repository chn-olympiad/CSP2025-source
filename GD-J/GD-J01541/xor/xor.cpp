#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],i,maxn,minn,cnt0=0,cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(a[i]==1)cnt1++;
		if(a[i]==0)cnt0++;
	}if(maxn==1&&minn==1)cout<<n/2;
	else if(maxn==1&&minn==0){
		if(k==1)cout<<cnt1;
		if(k==0){
			int ans=0;
			for(i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}else if(a[i]==0)ans++;
			}cout<<ans;
		}
	}return 0;
}
