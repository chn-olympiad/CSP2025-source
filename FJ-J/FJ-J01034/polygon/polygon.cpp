#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,ans=0,zsum=0,a[5005];
bool b[5005];
void dfs(int x,int c,int zd,int sum){//d:总共根数 c:当前根数 zd:当前最大 sum:当前总和
	if(c==x){
		if(zd*2<sum){
			ans++;
			ans%=mod;
		}
		return ;
	}
	if(zd*2>zsum){
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			c++;
			sum+=a[i];
			if(a[i]>zd){
				dfs(x,c,a[i],sum);
			}else{
				dfs(x,c,zd,sum);
			}
			c--;
			sum-=a[i];
		}
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zsum+=a[i];
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[n]*2>=zsum){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	for(int i=3;i<=n-1;i++){
		dfs(i,0,0,0);
	}
	if(a[n]*2<zsum){
		ans++;
	}
	cout<<ans;
	return 0;
}
