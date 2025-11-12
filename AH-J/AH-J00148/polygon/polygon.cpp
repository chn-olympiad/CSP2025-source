#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		int cmt=0,maxx=-1;
		for(int i=1;i<=n;i++)
		{
			cmt+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			maxx=max(a[i],maxx);
		}
		if(maxx*2<=cmt) cout<<1;
		else cout<<0;
	}
	else{
		int cmt=0;
		for(int i=1;i<n-1;i++)
		{ 
			cmt+=i;
			cmt%=998244353;
		}
		cout<<cmt;}	
		return 0;
}



