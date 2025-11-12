#include<bits/stdc++.h>
using namespace std;
int n,k,s,now=0,ans=0,a[500001],lst[1<<20];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	fill(lst,end(lst),-1);
	lst[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i],s^=a[i];
		if(now<=lst[s^k])++ans,now=i;
		lst[s]=i;
	}cout<<ans;
}