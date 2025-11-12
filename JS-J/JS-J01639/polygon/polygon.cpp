#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5010],ans;
int t[5000000][2],len=0;
map<int,int>mp;
bool flag=1;
void slove(){
	long long ans=0,a=n*(n-1)/2;
	for(int i=3;i<=n;i++){
		a=(a*(n-i+1)/i)%mod;
		ans=(ans+a)%mod;
	}
	printf("%lld",ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) flag=0;
	}
	if(flag==1){
		slove();
		return 0;
	}
	sort(a+1,a+n+1);
	map<int,int>::iterator it;
	for(int i=3;i<=n;i++){
		mp.clear();
		mp[0]=1;
		for(int j=1;j<i;j++){
			len=0;
			for(it=mp.begin();it!=mp.end();it++){
				len++;
				t[len][0]=it->first;
				t[len][1]=it->second;
			}
			for(int k=len;k>=1;k--){
				mp[t[k][0]+a[j]]=t[k][1]+1;
			}
		}
		for(it=mp.begin();it!=mp.end();it++){
			if((it->first)>a[i]) ans+=(it->second*1LL);
			ans=ans%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
