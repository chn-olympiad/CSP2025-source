#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=520,mod=998244353ll;
ll n,m,p[N],cnt1,ans,c[N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("F:/down/employ/employ2.in","r",stdin);
//	freopen("employ.txt","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(ll i=1;i<=n;i++)
		if(s[i]=='1')
			cnt1++;
	for(ll i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	if(m==n){
		for(int i=1;i<=n;i++)
			if(c[i]==0){
				puts("0");
				return 0;
			}
		if(cnt1!=n){
			puts("0");
			return 0;
		}
	}
	if(cnt1==n){
		ans=1;
		for(ll i=1;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=10){
		for(ll i=1;i<=n;i++)p[i]=i;
		do{
			ll tmp=0,cnt=0;
//			for(ll i=1;i<=n;i++)
//				cout<<s[i]<<' ';
//			cout<<endl;
			for(ll i=1;i<=n;i++){
//				cout<<p[i]<<'_'<<c[p[i]]<<' ';
				if(s[i]=='0'||tmp>=c[p[i]])tmp++;
				else ++cnt;
			}
//			cout<<cnt<<"!!\n";
			if(cnt>=m)++ans;
		}while(next_permutation(p+1,p+1+n));
		printf("%lld\n",ans);
		return 0;
	}
	puts("0");
	return 0;
}
