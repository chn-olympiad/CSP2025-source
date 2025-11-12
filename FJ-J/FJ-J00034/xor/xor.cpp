#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k,ans;
ll a[500007];
ll x[500007];
bool b[500007];
ll xx(int l,int r){
	return x[l-1]^x[r];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		x[i]=x[i-1]^a[i];
		if(a[i]==k)ans++,b[i]=1;
	}
	for(int i=1,j=2,r=0;i<n;i++,j=i+1){
		if(b[i])continue;
		while(xx(i,j)!=k && j<=n && !b[j])j++;
		if(j<=n && !b[j]){
			if(i>r)r=j,ans++;
			else if(j<r)r=j;
		}
	}
	cout<<ans;
	return 0;
}
