#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500009]={};
ll ans=0,f=1,f1=1,y=0,l=0,n=0,k=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]!=1&&a[i]!=0)f1=0;
		if(a[i]==1) y++;
		if(a[i]==0) l++;
	}
	if(f==1&&k==0)for(ll i=2;i<=n;i+=2)ans=ans+1+n-i;
	else if(f1==1){
		if(k==1)ans=y;
		if(k==0)ans=l;
	}
	cout<<ans;
	return 0;
}
