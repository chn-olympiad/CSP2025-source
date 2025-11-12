#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll d[15],n,m,c[505],ans,cnt1,cnt2;
char s[505];
bool b[15];
void f(ll x){
	if(x>n){
		ans%=p;
		ll s1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&i-s1-1<c[d[i]])s1++;
		}
		if(s1>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			d[x]=i;
			f(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]),cnt1+=c[i],cnt2+=1-c[i];
	if(n<=10){
		f(1);
		printf("%lld",ans%p);
	}
	else if(m==1){
		ll t=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){t=i;break;}
		}
		for(int i=1;i<=n;i++){
			if(c[i]>=t){
				ll ans1=1;
				for(int j=1;j<n;j++){
					ans1*=j;
					ans1%=p;
				}
				ans+=ans1;
				ans%=p;
			}
		}
		printf("%lld",ans);
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){printf("0");return 0;}
		}
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=p;
		}
		printf("%lld",ans);
	}
	else if(cnt1==n){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=p;
		}
		printf("%lld",ans);		
	}
	else printf("0");
	return 0;
}

