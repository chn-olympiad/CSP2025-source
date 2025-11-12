#include<bits/stdc++.h>
using namespace std;
const int mod=998244353; 
int n,ans;
int a[5005];
void dfs(int ch,int x,int h,int maxd,int z){
	if(x==z){
		if(h>maxd*2){
			ans=(ans+1)%mod;
			return;
		}
	}
	for(int i=ch+1;i<=n;i++){
		dfs(i,x+1,h+a[i],a[i],z);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,1,0,0,i);
	}
	int h=0;
	for(int i=1;i<=n;i++) h+=a[i];
	if(h>a[n]*2) ans=(ans+1)%mod;
	cout<<ans;
	return 0;
}

