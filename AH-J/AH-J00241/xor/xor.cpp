#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ans,b,e;
int a[500005];
int id[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++,id[cnt]=i;
	}
	for(int i=2;i<=cnt;i++)ans+=max(a[i]-a[i-1]-1,1);
	if(k==1)cout<<cnt;
	else if(k==0)cout<<ans;
	return 0;
}
