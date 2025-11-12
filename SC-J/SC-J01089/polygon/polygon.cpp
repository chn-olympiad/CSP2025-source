#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int S=1.5e6+5;
const int Q=998244353;
int n,a[N];
long long fac[N],inv[N],ans;
long long ksm(long long a1,int p1){
	long long sum=1;
	while(p1){
		if(p1&1){
			sum=sum*a1%Q;
		}
		a1=a1*a1%Q;
		p1>>=1;
	}
	return sum;
}
long long C(int nn,int mm){
	if(!nn||nn<mm) return 0ll;
	if(nn==mm||mm==0) return 1ll;
	return fac[nn]*inv[mm]%Q*inv[nn-mm]%Q;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool op1=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) op1=0;
	}
	if(op1){
		fac[0]=inv[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%Q;
			inv[i]=ksm(fac[i],Q-2);
//			cout<<fac[i]<<" "<<inv[i]<<endl;
		}
		for(int i=3;i<=n;i++){
			ans=ans+C(n,i);
		}
		printf("%lld",ans);
	}else{
		for(int s=7;s<=(1<<n)-1;s++){
			int sum=0,mxn=0,cnt=0;
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1){
					sum+=a[i]; cnt++;
					mxn=max(mxn,a[i]);
				}
			}
			if(cnt<3) continue;
			if(sum>2*mxn) ans++;
		}
		printf("%lld",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}