#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e6+10;
ll n,m,k,h[N],idx,u,v,w,c[100],a[100][20000],p[N],ans;
bool used[100];
struct Edge{
	ll to,from,w;
	bool operator<(const Edge&_)const{
		return w<_.w;
	}
}e[N];
void add(ll u,ll v,ll w){
	e[++idx].from=u;
	e[idx].to=v;
	e[idx].w=w;
}ll find(ll x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n+k;i++)
		p[i]=i;
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		//add(v,u,w);
	}for(ll j=1;j<=k;j++){
		scanf("%lld",c+j);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[j][i]); 
			add(n+j,i,a[j][i]);
			//add(i,j+n,a[j][i]);
		}
			
	}sort(e+1,e+1+m+k*n);
	if(k==0){
		ll cur=0;
		for(ll i=1;i<=m;i++){
			ll to=e[i].to,from=e[i].from,w=e[i].w;
			//printf("(%lld,%lld,%lld)\n",from,to,w);
			ll pf=find(from),pt=find(to);
			if(pf<=n&&pt<=n){
				if(pf!=pt){
					
					p[pf]=pt;
					cur++;
					//printf("add(%lld,%lld) cur=%lld n-1=%lld\n",pf,pt,cur,n-1);
					ans+=w;
				}//printf("cur:%lld n-1:%lld\n",cur,n-1);
				if(cur>=n-1){
					break;
				}	
			}
			
				
		}printf("%lld\n",ans);
		
	}else{
		
		ans=1e18;
		for(ll l=0;l<(1<<k);l++){
			bool flag=1; 
			ll res=0ll;
			for(ll i=1;i<=n+k;i++)//
				p[i]=i;
			memset(used,0,sizeof used);
			for(ll j=1;j<=10;j++) {
				used[j]=(l>>(j-1))&1;
				if(used[j]){
					res+=c[j];
				}
			}ll cur=0;
			for(ll i=1;i<=m+k*n;i++){
				ll to=e[i].to,from=e[i].from,w=e[i].w;
				
				//printf("(%lld,%lld,%lld)\n",from,to,w);
				//printf("to:%lld from:%lld\n",to,from);
				ll pf=find(from),pt=find(to);
				if(pf==pt) continue;
				/*
				if(to>n)
				printf("used[%lld]=%lld ",to-n,used[to-n]);
				if(from>n)
				printf("used[%lld]=%lld ",from-n,used[from-n]);
				printf("\n------------------\n");
				*/
				if(res>ans){
					flag=0;
					break; 
				}
				if((from<=n||(from>n&&used[from-n]))&&(to<=n||(to>n&&used[to-n]))){//
					if(pf!=pt){
						if(find(pf)<n&&find(pt)!=find(pt))
						if(pf<=n&&pt<=n)
							cur++;
						p[max(pf,pt)]=min(pf,pt);
						
						
						res+=w;
					}if(cur>=n-1){
						break;
					}
				}
				
					
			}
			
			if(flag)
				ans=min(ans,res); 
			//printf("l:%lld res:%lld\n",l,res);
			//printf("\n----------------------------------------\n");
		}
		printf("%lld\n",ans);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

