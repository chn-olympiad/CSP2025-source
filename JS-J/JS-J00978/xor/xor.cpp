#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%lld%lld",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	if(k==0){
		int cnt=0;
		for(int i=0;i<n;i++)if(a[i]==0)cnt++;
		for(int i=1;i<n;i++)if(a[i]==1&&a[i-1]==1)cnt++,i++;
		cout<<cnt;
		exit(0);
	}
	if(k==1){
		int cnt=0;
		for(int i=0;i<n;i++)if(a[i]==1)cnt++;
		cout<<cnt;
		exit(0);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int mn=n;
		for(int j=i;j<mn;j++){
			int cnt=0,x=j;
			while(cnt!=k&&x<n){
				cnt^=a[x];
				x++;
			}
			if(x!=n)mn=min(mn,x);
		}
		if(mn!=n){
			i=mn;
			ans++;
		}
	}
	cout<<ans;
}
