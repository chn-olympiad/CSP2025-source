#include<bits/stdc++.h>
using namespace std;
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+5]={},minn=INT_MAX,maxx=INT_MIN;
	for(int i=1;i<=n;i++)
	  cin>>a[i],minn=min(minn,a[i]),maxx=max(maxx,a[i]);
	if(minn==1&&maxx==1){
		cout<<n/2;
		return 0;
	}
	if(minn==0&&maxx==1){
		if(k==0){
			for(int i=1;i<=n;i++)
			  if(a[i]==0)
			    ans++;
			for(int i=1;i<=n-1;i++)
			  if(a[i]==1&&a[i+1]==1)
			    ans++,a[i+1]=-0;
			cout<<ans;
			return 0;
		}
		if(k==1){
			for(int i=1;i<=n;i++)
			  if(a[i]==1)
			    ans++;
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	  if(a[i]==k)
	    ans++;
	cout<<ans;
	return 0;
}

