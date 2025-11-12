#include<bits/stdc++.h>
using namespace std;
long long p[501],d[501],t[501],sum[501],ans=1,men,mod=998244353;
int c,n,m;
string s;
long long A(int x){
	long long cnt=1;
	for(int i=1;i<=x;i++)cnt=(cnt*i)%mod;
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;men=n;
	cin>>s;
	for(int i=0;i<s.size();i++){if(s[i]=='1')d[++c]=i+1;}
	for(int i=1;i<=n;i++)cin>>p[i],t[p[i]]++;
	if(c<m)return printf("0"),0;
	sum[0]=t[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+t[i];
	for(int i=m;i>=1;i--){
		int r=d[i]-i,q=men-sum[r];
		if(!q)return printf("0"),0;
		//printf("%d %d %d\n",r,men,q);
		ans=(ans*q)%mod;men--;
	}
	ans=(ans*A(men)%mod);
	printf("%lld",ans);
	return 0;
}
