#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N],ans,vis[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			int tmp=0,sum=0,maxx=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					tmp++;
					sum+=a[j];
					maxx=max(maxx,a[j]);
				}
			}
			if(tmp>=3&&sum>maxx*2) ans++; 
		}
		cout<<ans;
	}
	else{
		bool flg=true;
		for(int i=1;i<=n;i++)
			if(a[i]!=1) flg=false;
		if(flg){
			int y=n; long long x=2,ans=1;
			while(y){
				if(y&1) ans=ans*x%MOD;
				x=x*x%MOD; y>>=1;
			}
			cout<<(ans-1-n-n*(n-1)/2+MOD)%MOD;
		}
	}
	return 0;
}
