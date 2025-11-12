#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct note{
	int a,b,c;
}a[100010];
int flag;
int d[100010];
int vi[100010];
int va[100010],vb[100010],vc[100010];
int sa,sb,sc;
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(d,0,sizeof(d));
		memset(va,0,sizeof(va));
		memset(vb,0,sizeof(vb));
		memset(vc,0,sizeof(vc));
		memset(vi,0,sizeof(vi));
		sa=sb=sc=0;
		cin>>n;
		flag=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0) flag=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				if(sa<n/2){
					va[++sa]=i;
					d[i]=1;
					vi[i]=sa;
					ans+=a[i].a;
				}
				else{
					int x=va[1];
					for(int j=1;j<=sa;j++){
						if(min(a[va[j]].a-a[va[j]].b,a[va[j]].a-a[va[j]].c)<min(a[x].a-a[x].b,a[x].a-a[x].c)) x=va[j]; 
					}
					if(min(a[i].a-a[i].b,a[i].a-a[i].c)>min(a[x].a-a[x].b,a[x].a-a[x].c)){
						va[vi[x]]=i;
						d[i]=1;
						vi[i]=vi[x];
						ans+=a[i].a;
						if(a[x].b>a[x].c){
							vb[++sb]=x;
							d[x]=2;
							vi[x]=sb;
							ans+=a[x].b-a[x].a;
						}
						else{
							vc[++sc]=x;
							d[x]=3;
							vi[x]=sc;
							ans+=a[x].c-a[x].a;
						}
					}
					else{
						if(a[i].b>a[i].c){
							vb[++sb]=i;
							d[i]=2;
							vi[i]=sb;
							ans+=a[i].b;
						}
						else{
							vc[++sc]=i;
							d[i]=3;
							vi[i]=sc;
							ans+=a[i].c;
						}
					}
				}
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				if(sb<n/2){
					vb[++sb]=i;
					d[i]=2;
					vi[i]=sb;
					ans+=a[i].b;
				}
				else{
					int x=vb[1];
					for(int j=1;j<=sb;j++){
						if(min(a[vb[j]].b-a[vb[j]].a,a[vb[j]].b-a[vb[j]].c)<min(a[x].b-a[x].a,a[x].b-a[x].c)) x=vb[j]; 
					}
					if(min(a[i].b-a[i].a,a[i].b-a[i].c)>min(a[x].b-a[x].a,a[x].b-a[x].c)){
						vb[vi[x]]=i;
						d[i]=2;
						vi[i]=vi[x];
						ans+=a[i].b;
						if(a[x].a>a[x].c){
							va[++sa]=x;
							d[x]=1;
							vi[x]=sa;
							ans+=a[x].a-a[x].b;
						}
						else{
							vc[++sc]=x;
							d[x]=3;
							vi[x]=sc;
							ans+=a[x].c-a[x].b;
						}
					}
					else{
						if(a[i].a>a[i].c){
							va[++sa]=i;
							d[i]=1;
							vi[i]=sa;
							ans+=a[i].a;
						}
						else{
							vc[++sc]=i;
							d[i]=3;
							vi[i]=sc;
							ans+=a[i].c;
						}
					}
				}
			}
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				if(sc<n/2){
					vc[++sc]=i;
					d[i]=3;
					vi[i]=sc;
					ans+=a[i].c;
				}
				else{
					int x=vc[1];
					for(int j=1;j<=sc;j++){
						if(min(a[vc[j]].c-a[vc[j]].b,a[vc[j]].c-a[vc[j]].a)<min(a[x].c-a[x].b,a[x].c-a[x].a)) x=vc[j]; 
					}
					if(min(a[i].c-a[i].b,a[i].c-a[i].a)>min(a[x].c-a[x].b,a[x].c-a[x].a)){
						vc[vi[x]]=i;
						d[i]=3;
						vi[i]=vi[x];
						ans+=a[i].c;
						if(a[x].b>a[x].a){
							vb[++sb]=x;
							d[x]=2;
							vi[x]=sb;
							ans+=a[x].b-a[x].c;
						}
						else{
							va[++sa]=x;
							d[x]=1;
							vi[x]=sa;
							ans+=a[x].a-a[x].c;
						}
					}
					else{
						if(a[i].b>a[i].a){
							vb[++sb]=i;
							d[i]=2;
							vi[i]=sb;
							ans+=a[i].b;
						}
						else{
							va[++sa]=i;
							d[i]=1;
							vi[i]=sa;
							ans+=a[i].a;
						}
					}
				}
			}
//			if(a[i].a==a[i].b) cout<<i<<" ";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
