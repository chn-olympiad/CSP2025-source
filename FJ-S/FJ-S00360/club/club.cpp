#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{int a,b,c;}e[N];
struct node{int a,b,c,mc;}e2[N];
int i,j,T,n,at,bt,ct,x,y,z,ans;
bool cmpbc0(Node x,Node y){return x.a>y.a;}
bool cmpc0(Node x,Node y){return (x.a-x.b)>(y.a-y.b);}
bool cmp(node x,node y){return max({x.a,x.b,x.c})>max({y.a,y.b,y.c});}
int dfs(int x,int ta,int tb,int tc){
	if(x>n) return 0;
	int res=0;
	if(ta<n/2) res=max(res,e[x].a+dfs(x+1,ta+1,tb,tc));
	if(tb<n/2) res=max(res,e[x].b+dfs(x+1,ta,tb+1,tc));
	if(tc<n/2) res=max(res,e[x].c+dfs(x+1,ta,tb,tc+1));
	return res;
}
void solve(){
	int b0=0,c0=0;
	for(cin>>n,at=bt=ct=ans=0,i=1;i<=n;i++) cin>>x>>y>>z,b0+=(y==0),c0+=(z==0),e2[i]={x-z,y-z,0,z},e[i]={x,y,z};
	if(b0==n&&c0==n){
		sort(e+1,e+1+n,cmpbc0);
		for(int i=1;i<=n/2;i++) ans+=e[i].a;
		return cout<<ans,void();
	}
	if(c0==n){
		sort(e+1,e+1+n,cmpc0);
		for(int i=1;i<=n;i++){
			if(e[i].a>e[i].b){
				if(at==n/2) ans+=e[i].b;
				else ans+=e[i].a;
			}
			else{
				if(bt==n/2) ans+=e[i].a;
				else ans+=e[i].b;
			}
		}
		return cout<<ans,void();
	}
	if(n<=30) cout<<max({dfs(1,0,0,0)})<<'\n';
	else{
		int ta=0,tb=0,tc=0;
		sort(e2+1,e2+1+n,cmp);
		for(i=1;i<=n;i++){
			int a=e2[i].a,b=e2[i].b,c=e2[i].c;
			if(a>b&&a>c){
				if(ta==(n>>1)){
					if(b>c) tb++,ans+=b+e2[i].mc;
					else tc++,ans+=c+e2[i].mc;
				}
				else ta++,ans+=a+e2[i].mc;
			}
			else if(b>c){
				if(tb==(n>>1)){
					if(a>c) ta++,ans+=a+e2[i].mc;
					else tc++,ans+=c+e2[i].mc;
				}
				else tb++,ans+=b+e2[i].mc;
			}
			else{
				if(tc==(n>>1)){
					if(a>b) ta++,ans+=a+e2[i].mc;
					else tb++,ans+=b+e2[i].mc;
				}
				else tc++,ans+=c+e2[i].mc;
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T--;solve());
	return 0;
}//40pts
