#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;i++)
#define int long long
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1],s[n+1];
	s[0]=0;
	fo(i,1,n) cin>>a[i],s[i]=s[i-1]^a[i];
	int now=0,ans=0;
	fo(i,1,n){
		fo(j,now+1,i){
			if((s[i]^s[j-1])==k) ans++,now=i;
			if(now+1>i) break;
		}
	}
	cout<<ans;
	return 0;
}