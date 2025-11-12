#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
ll n,q=0,a[20005],b[20005],si[20005],c[20005],d[20005];
char s[500005],s1[500005];
ll t[100005],t1[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,s1+1);
		ll x=strlen(s+1),y=strlen(s1+1);
		si[i]=x;
		ll sa=0,cb=0;
		for(int j=1;j<=x;j++)
			sa+=(s[j]-96)*j,sa%=p,c[i]+=s[j]-96;
		for(int j=1;j<=y;j++)
			cb+=(s1[j]-96)*j,cb%=p,d[i]+=s1[j]-96;
		a[i]=sa,b[i]=cb;
	}
	while(q>0){
		q--;
		ll ans=0;
		t[0]=t1[0]=0;
		scanf("%s%s",s+1,s1+1);
		ll x=strlen(s+1);
		for(int i=1;i<=x;i++)
			t[i]=(s[i]-96)*i+t[i-1],t[i]%=p;
		for(int i=1;i<=x;i++)
			t1[i]=(s1[i]-96)*i+t1[i-1],t1[i]%=p;
		for(int i=1;i<=x;i++){
			bool f=0;
			for(int j=1;j<=n;j++){
				if(i+si[j]-1>x)continue;
				f=1;
				ll k=i+si[j]-1;
				if(((t[k]-t[i-1])-a[j]+p+p)%p==(c[j]*(i-1))%p){
					if((t[x]-a[j]-c[j]*(i-1)+b[j]+d[j]*(i-1)+p)%p==t1[x])ans++;
				}
			}
			if(!f)break;
		}	
		printf("%lld ",ans);
	} 
	return 0;
}

