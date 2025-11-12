#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
struct node{
	int v,id;
}a[N],b[N],c[N];
int t,n,ans=0;
int cnta=0,cntb=0,cntc=0;
int suma=0,sumb=0,sumc=0;
int vis[N];
inline bool cmp(node x,node y){
	if(x.v!=y.v){
		return x.v>y.v;
	}
	return x.id<y.id;
}
inline int min3(int a,int b,int c){
	return min(min(a,b),c);
}
inline void init(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(vis,0,sizeof(vis));
	cnta=0;cntb=0;cntc=0;
	suma=0;sumb=0;sumc=0;
	ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].v>>b[i].v>>c[i].v;
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
			cnta+=a[i].v;
			cntb+=b[i].v;
			cntc+=c[i].v;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(cnta==0&&cntb==0&&cntc==0){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(suma+sumb+sumc==n){
				break;
			}
			int ida=a[i].id,idb=b[i].id,idc=c[i].id;
			int av=a[i].v,bv=b[i].v,cv=c[i].v;
//			cout<<ans<<endl;
			if(ida==idb&&idb==idc){
				if(min3(suma,sumb,sumc)==suma){
					suma++;
				}
				else if(min3(suma,sumb,sumc)==sumb){
					sumb++;
				}
				else{
					sumc++;
				}
				vis[ida]=1;
				ans+=av;
				continue;
			}
			if(ida==idb&&!vis[ida]){
				if(av>bv||suma<sumb){
					suma++;
				}
				else{
					sumb++;
				}
				vis[ida]=1;
				ans+=av;
				if(sumc<=n/2&&!vis[idc]){
					vis[idc]=1;
					sumb++;
					ans+=cv;
				}
				continue;
			}
			else if(idb==idc&&!vis[idb]){
				if(bv>cv||sumb<sumc){
					sumb++;
				}
				else{
					sumc++;
				}
				vis[idb]=1;
				ans+=bv;
				if(suma<=n/2&&!vis[ida]){
					vis[ida]=1;
					suma++;
					ans+=av;
				}
				continue;
			}
			else if(ida==idc&&!vis[ida]){
				if(av>cv||suma<sumc){
					suma++;
				}
				else{
					sumc++;
				}
				vis[ida]=1;
				ans+=av;
				if(sumb<=n/2&&!vis[idb]){
					vis[idb]=1;
					sumb++;
					ans+=bv;
				}
				continue;
			}
			if(suma<=n/2&&!vis[ida]){
				vis[ida]=1;
				suma++;
				ans+=av;
			}
			if(sumb<=n/2&&!vis[idb]){
				vis[idb]=1;
				sumb++;
				ans+=bv;
			}
			if(sumc<=n/2&&!vis[idc]){
				vis[idc]=1;
				sumb++;
				ans+=cv;
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
0 1 0
0 1 0
0 2 0
0 2 0

4
4 2 1
3 2 4
5 3 4
3 5 1

2
10 9 8
4 0 0

4
18
13
*/
