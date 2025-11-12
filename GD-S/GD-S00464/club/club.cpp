#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+5;
long long t,n;
struct node{
	long long a,b,c;
}op[N];
long long ans,suma,sumb,sumc;
long long choose[N];
struct num{
	long long val,id;
	friend bool operator<(num x,num y){
		return x.val<y.val;
	}
}c[N<<1];
bool vis[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		suma=0,sumb=0,sumc=0;
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>op[i].a>>op[i].b>>op[i].c;
		ans=0;
		for(long long i=1;i<=n;i++){
			if(op[i].a>=op[i].b&&op[i].a>=op[i].c){
				choose[i]=1,ans+=op[i].a,suma++;continue;
			}
			if(op[i].b>=op[i].a&&op[i].b>=op[i].c){
				choose[i]=2,ans+=op[i].b,sumb++;continue;
			}
			if(op[i].c>=op[i].a&&op[i].c>=op[i].b){
				choose[i]=3,ans+=op[i].c,sumc++;continue;
			}
		}
		if(suma>n/2){
			for(long long i=1;i<=n;i++){
				if(choose[i]==1){
					c[i].val=op[i].a-op[i].b,c[i+n].val=op[i].a-op[i].c;
					c[i].id=i,c[i+n].id=i;
				}
				else c[i].val=1e18,c[i+n].val=1e18;
			}
			sort(c+1,c+2*n+1);
			for(long long i=1;i<=2*n;i++){
				if(vis[c[i].id]) continue;
				ans-=c[i].val;vis[c[i].id]=1;
				suma--;
				if(suma==n/2) break;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(sumb>n/2){
			for(long long i=1;i<=n;i++){
				if(choose[i]==2){
					c[i].val=op[i].b-op[i].a,c[i+n].val=op[i].b-op[i].c;
					c[i].id=i,c[i+n].id=i;
				}
				else c[i].val=1e18,c[i+n].val=1e18;
			}
			sort(c+1,c+2*n+1);
			for(long long i=1;i<=2*n;i++){
				if(vis[c[i].id]) continue;
				ans-=c[i].val;vis[c[i].id]=1;
				sumb--;
				if(sumb==n/2) break;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(sumc>n/2){
			for(long long i=1;i<=n;i++){
				if(choose[i]==3){
					c[i].val=op[i].c-op[i].a,c[i+n].val=op[i].c-op[i].b;
					c[i].id=i,c[i+n].id=i;
				}
				else c[i].val=1e18,c[i+n].val=1e18;
			}
			sort(c+1,c+2*n+1);
			for(long long i=1;i<=2*n;i++){
				if(vis[c[i].id]) continue;
				ans-=c[i].val;vis[c[i].id]=1;
				sumc--;
				if(sumc==n/2) break;
			}
			cout<<ans<<"\n";
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
