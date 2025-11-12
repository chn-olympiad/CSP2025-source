#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}
int c[505],a[505],b[505];
char s[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') sum++;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	sort(c+1,c+n+1);
	if(n<=18){
		for(int i=1;i<=n;i++) a[i]=i;
		int ans=0;
		do{
			sum=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||sum>=c[a[i]]) sum++;
			}
			if(n-sum>=m) ans++;
		}while(next_permutation(a+1,a+n+1));
		printf("%lld",ans);
	}
	else if(m==n){
		if(sum!=n||c[1]==0) cout<<0;
		else{
			sum=1;
			for(int i=1;i<=n;i++){
				sum=(sum*i)%MOD;
			}
			cout<<sum;
		}
	}
	else if(m==1){//这个过不了，但还是交了 
		int ans=0,lst=1;a[0]=b[0]=1;sum=0;
		for(int i=1;i<=n;i++) a[i]=(a[i-1]*i)%MOD,b[i]=ksm(a[i],MOD-2);
		for(int i=1,j=1;i<=n&&j<=n;i++){
			if(s[i]=='1'){
				while(j<=n&&c[j]<i) j++;
				ans=(ans+((n-j+1)*lst%MOD)%MOD*a[n-i]%MOD*b[max(0ll,i-1)])%MOD;
				lst=(lst*(j-1-sum))%MOD,sum++;
			}
		}
		cout<<ans;
	}
	else puts("0");//泪目 
	return 0;
}
