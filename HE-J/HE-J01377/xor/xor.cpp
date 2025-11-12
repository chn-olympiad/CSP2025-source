#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll op(ll x,ll y)//ËãÒì»ò
{
	ll ans=0,i=1;
	while(!((!x)&&(!y))){
		if(x%2!=y%2) ans+=i;
		i*=2,x/=2,y/=2;
	}
	return ans;
}

ll n,k,a[514114],s[514114],t[514114],tmp=0;

bool flag1=1,flag2=1;

void mmm(ll l,ll r,ll ans)
{
	if(l>r){
		tmp=max(tmp,ans);
		return;
	}
	else{
		for(ll len=1;len<=r-l+1;len++){
			for(ll i=l;i+len-1<=r;i++){
				ll j=i+len-1;
				int q=a[i];
				for(ll kk=i+1;kk<=r;kk++) q=op(q,a[kk]);
				if(q==k) mmm(j,r,ans+1);
			}
		}
	}
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) flag1=0;
		if(a[i]!=0&&a[i]!=1) flag2=0;
	}
	if(flag1){
		if(k==0) printf("%lld",n/2);
		else printf("%lld",n);
	}
	else if(flag2&&(k==1||k==0)){
		ll ans=0;
		if(k==0){
			ll l=1,r=1;
			for(r=1;r<=n;r++){
				if((l!=r&&a[l]==a[r])||a[r]==0){
					l=r+1;
					ans++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		}
		printf("%lld",ans);
	}
	else{
		ll ans=0,tot=0;
		for(int l=1,r=1;r<=n;r++){
			if(a[r]==k){
				ans++;
				if(l==r){
					l++;
					continue;
				}
				s[++tot]=l;
				t[tot]=r-1;
				l=r+1;
			}
			else if(r==n){
				s[++tot]=l;
				t[tot]=r;
			}
		}
		if(tot==0) s[1]=1,t[1]=n,tot++;
		for(int i=1;i<=tot;i++){
			ll l=s[i],r=t[i];
			tmp=0;
			mmm(l,r,0);
			ans+=tmp;
		}
		printf("%lld",ans);
	}
	return 0;
}
