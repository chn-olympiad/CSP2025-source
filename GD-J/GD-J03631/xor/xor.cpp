#include<bits/stdc++.h>
#define int long long
const int N=5e5+10;
using namespace std;
int n,k,ans,cnt,a[N];
signed main(){
	freopen("xor.in","r","std.in");
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	int f1=1,f2=1;
	for(int i=1;i<=n;++i){
		if(a[i]!=1) f1=0;
		if(a[i]!=0&&a[i]!=1) f2=0;
	}
	if(f1) ans=n/2;
	else if(f2){
		for(int i=1;i<=n;++i) if(a[i]==1) cnt++;
		if(!k) ans=cnt/2;
		else if(k==1) ans=cnt;
	}
	cout<<ans;
	freopen("xor.out","w","std.out");
	return 0;
}
