#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,s[501],c[501],sum;
long long ans;
bool bj[501];
void dog(int wz,int rs){
	if(-~rs+n-wz<m)return;
	if(wz>n){
		if(rs>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!bj[i]){
			bj[i]=true;
			if(wz-1>c[i]||s[wz]==0)dog(-~wz,rs);
			else dog(-~wz,-~rs);
			bj[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%1d",&s[i]);
		sum+=s[i];
	}
	if(sum<m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	if(m==n){
		for(int i=1;i<=n;++i)
			if(s[i]==0){
				s[0]=1;
				break;
			}
		if(s[0])printf("0");
		ans=1;
		for(int i=2;i<=n;++i)
			ans=(ans*i)%mod;
		printf("%lld",ans);
		return 0;
	}
	if(m==1){
		int i=1;long long sum=1;
		for(int i=2;i<n;++i)
			sum=sum*i%mod;
		while(s[i]==0)++i;
		for(int j=1;j<=n;++j){
			if(c[j]>=i){
				ans=(ans+sum)%mod;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	dog(1,0);
	printf("%lld",ans);
	return 0;
}
