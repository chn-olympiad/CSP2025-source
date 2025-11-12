#include<iostream>
#include<cstdio>
#include<algorithm>

#define ll long long 

using namespace std;

const int M=1e5+5;

struct node{
	ll v,id;
	ll w[5];
};

struct jnt{
	ll v,w;
};

node a[M];

jnt b[5];
ll tmpb[M];

ll n,m,ans;

void dfs(ll k){
	if(k>n){
		ll tmp=0;
		for(ll i=1;i<=3;i++){
			tmp+=b[i].w;
		}
		ans=max(ans,(long long)tmp);
		return;
	}
	for(ll i=1;i<=3;i++){
		if(b[i].v<m){
			b[i].w+=a[k].w[i];
			b[i].v++;
			dfs(k+1);
			b[i].v--;
			b[i].w-=a[k].w[i]; 
		}
	}
}

void f(){
	ans=0;
	dfs(1);
	printf("%lld\n",ans);
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ll T;
	scanf("%lld",&T);
	
	while(T--){
		bool f_a=true,f_b=true;
		
		scanf("%lld",&n);
		
		ans=0;
		
		m=n/2;
		
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].w[1],&a[i].w[2],&a[i].w[3]);
			a[i].v=0;
			a[i].id=i;
			if(a[i].w[2]!=0){
				f_a=false;
			}
			if(a[i].w[3]!=0){
				f_a=false;
				f_b=false;
			}
		}
		
		for(ll i=1;i<=3;i++){
			b[i].v=0;
			b[i].w=0;
		}
		
		if(n<=10){
			f();
			continue;
		}
		
		if(f_a){
			for(ll i=1;i<=n;i++){
				tmpb[i]=a[i].w[1];
			} 
			sort(tmpb+1,tmpb+n+1);
			ans=0;
			for(ll i=1;i<=m;i++){
				ans=ans+(long long)(tmpb[i]);
			}
			printf("%lld\n",ans);
			continue;
		}
		
		if(f_b){
			ans=0;
			ll sua=0,sub=0,kcc=0;
			for(ll i=1;i<=n;i++){
				if(a[i].w[1]==a[i].w[2])kcc++;
				if(a[i].w[1]>a[i].w[2]){
					sua++;
				}else{
					sub++;
				}
			}
			if(sua<=m&&sub<=m){
				for(ll i=1;i<=n;i++){
					ans=ans+(long long)(max(a[i].w[1],a[i].w[2]));
				}
			}else{
				if(sua>m){
					for(ll i=1;i<=n;i++){
						tmpb[i]=a[i].w[1]-a[i].w[2];
						ans=ans+(long long)(max(a[i].w[1],a[i].w[2]));
					}
					sort(tmpb+1,tmpb+n+1);
					for(ll i=1;i<=n;i++){
						if(sua<=m)break;
						ans-=tmpb[i];
						sua--;
					}
				}else{
					for(ll i=1;i<=n;i++){
						tmpb[i]=a[i].w[2]-a[i].w[1];
						ans=ans+(long long)(max(a[i].w[1],a[i].w[2]));
					}
					sort(tmpb+1,tmpb+n+1);
					for(ll i=1;i<=n;i++){
						if(sub<=m)break;
						ans-=tmpb[i];
						sub--;
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		
		ll ka=0,kb=0,kc=0;
		
		ans=0;
		
		for(ll i=1;i<=n;i++){
			if(a[i].w[1]>a[i].w[2]&&a[i].w[1]>a[i].w[3]){
				ka++;
			}
			if(a[i].w[2]>a[i].w[1]&&a[i].w[2]>a[i].w[3]){
				kb++;
			}
			if(a[i].w[3]>a[i].w[2]&&a[i].w[3]>a[i].w[1]){
				kc++;
			}
		}
		
		for(ll i=1;i<=n;i++){
			ans=ans+max(a[i].w[1],max(a[i].w[2],a[i].w[3]));
		}
		
		if(ka>m){
			for(ll i=1;i<=n;i++){
				tmpb[i]=min(a[i].w[1]-a[i].w[2],a[i].w[1]-a[i].w[3]);
			}
			sort(tmpb+1,tmpb+n+1);
			for(ll i=1;i<=n;i++){
				if(ka<=m)break;
				ans-=tmpb[i];
				ka--;
			}
		}
		if(kb>m){
			for(ll i=1;i<=n;i++){
				tmpb[i]=min(a[i].w[2]-a[i].w[1],a[i].w[2]-a[i].w[3]);
			}
			sort(tmpb+1,tmpb+n+1);
			for(ll i=1;i<=n;i++){
				if(kb<=m)break;
				ans-=tmpb[i];
				kb--;
			}
		}
		if(kc>m){
			for(ll i=1;i<=n;i++){
				tmpb[i]=min(a[i].w[3]-a[i].w[1],a[i].w[3]-a[i].w[2]);
			}
			sort(tmpb+1,tmpb+n+1);
			for(ll i=1;i<=n;i++){
				if(kc<=m)break;
				ans-=tmpb[i];
				kc--;
			}
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}

