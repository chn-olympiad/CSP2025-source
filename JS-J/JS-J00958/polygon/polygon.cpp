#include<bits/stdc++.h>
using namespace std;
const long long qq=998244353;
long long n,x1[5009],nn=0,x2[509],mm=0;
void qwe(long long x){
	long long ans=0,pp;
	if(x==n+1){
		for(long long i=n;i>=1;i--){
			ans+=x1[i]*x2[i];
			if(ans==x1[i])pp=ans;
		}
		if(ans>pp*2)mm=(mm+1)%qq;
		return;
	}
	x2[x]=1;
	qwe(x+1);
	x2[x]=0;
	qwe(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x1[i]);
		nn=max(nn,x1[i]);
	}
	sort(x1+1,x1+n+1);
	if(nn==1){
		long long t=n,w=1;
		while(t--){
			w*=2;
			w%=qq;
		}
		long long e=n*(n-1)/2%qq;
		long long r=(w+qq-1-n-e)%qq;
		printf("%lld",r);
	}else{
		qwe(1);
		printf("%lld",mm);
	}
	return 0;
}
