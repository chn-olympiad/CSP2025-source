#include<bits/stdc++.h>
#define N 510 
#define rint register int
using namespace std;
inline int read(){
	char c;
	int num_in=0,num_sign=1;
	for(;!isdigit(c);c=getchar())
		if(c=='-') num_sign=-1;
	for(;isdigit(c);c=getchar())
		num_in=(num_in<<3)+(num_in<<1)+(c^48);
	return num_in*num_sign; 
}
const long long MOD=998244353;
long long n,m,c[N],ans;
char a[N];
long long num_0,num_1,cnt=0,cnt0[N],cnt1[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(rint i=1;i<=n;i++){
		cin>>a[i];
		cnt0[i]=cnt0[i-1];
		cnt1[i]=cnt1[i-1];
		if(a[i]=='0') cnt0[i]++;
		if(a[i]=='1') cnt1[i]++;
	}
	for(rint i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		printf("0");
		return 0;
	}
	if(m==1){
		ans=1;
		long long op=0;
		for(op=1;op<=n;op++)
			if(cnt1[op]==1) break;
		op--;
		for(rint i=1;i<=n;i++){
			if(i!=n) ans=(ans*i)%MOD;
			if(c[i]>op) cnt++;
		}
		for(rint i=1;i<=cnt;i++){
			ans=(ans*2)%MOD;
		}
		printf("%lld",ans);
		return 0;
	}
}
