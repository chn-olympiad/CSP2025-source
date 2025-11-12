#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,Mod=998244353;
int n,ma,ans;
int a[N],b[N];
void dfs(int dep,int m,int h,int cnt){
	if(dep>n){
		if(h>2*m&&cnt>=3) ans=(ans+1)%Mod;
		return;
	}
	h+=a[dep],cnt++;
	dfs(dep+1,max(m,a[dep]),h,cnt);
	h-=a[dep],cnt--;
	dfs(dep+1,m,h,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	if(ma==1){
		for(int i=3;i<=n;i++){
			int x=1,y=i;
			if(i>n/2) y=n-i;
			for(int j=1;j<=y;j++){
				x=x*(n-j+1)%Mod;
				x/=j;
			}
			ans=(ans+x)%Mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans%Mod<<endl;
	return 0;
}
