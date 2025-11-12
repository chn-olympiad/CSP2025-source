#include<bits/stdc++.h>
#define fi first
#define se second
#define N 100005
#define ll long long
#define pli pair<ll,int>
using namespace std;
pli a[N],b[N],c[N];
ll aa[N],bb[N],cc[N];
bool cmp(pli a,pli b){
	return a.fi>b.fi;
}
void solve(){
	int n;
	int cnta,cntb,cntc;
	ll suma,sumb,sumc;
	suma=sumb=sumc=cnta=cntb=cntc=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi>>b[i].fi>>c[i].fi;
		suma+=a[i].fi;
		sumb+=b[i].fi;
		sumc+=c[i].fi;
		aa[i]=a[i].fi;
		bb[i]=b[i].fi;
		cc[i]=c[i].fi;
		a[i].se=b[i].se=c[i].se=i;	
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
		cnta=n;
		cntb=cntc=0;
		while(cnta>(n/2)){
			suma-=a[cnta].fi;
			int now=a[cnta].se;
			if(bb[now]>cc[now]){
				if(cntb<(n/2)){
					cntb++;
					suma+=bb[now];
				}else{
					cntc++;
					suma+=cc[now];
				}
			}else if(bb[now]<cc[now]){
				if(cntc>=(n/2)){
					cntb++;
					suma+=bb[now];
				}else{
					cntc++;
					suma+=cc[now];
				}
			}else{
				suma+=bb[now];
				if(cntc>cntb){
					cntb++;					
				}else{
					cntc++;
				}
			}
			cnta--;
		}
		cntb=n;
		cnta=cntc=0;
		while(cntb>(n/2)){
			sumb-=b[cntb].fi;
			int now=b[cntb].se;
			if(aa[now]>cc[now]){
				if(cnta<(n/2)){
					cnta++;
					sumb+=aa[now];
				}else{
					cntc++;
					sumb+=cc[now];
				}
			}else if(aa[now]<cc[now]){
				if(cnta>=(n/2)){
					cnta++;
					sumb+=aa[now];
				}else{
					cntc++;
					sumb+=cc[now];
				}
			}else{
				sumb+=aa[now];
				if(cntc>cnta){
					cnta++;					
				}else{
					cntc++;
				}
			}
			cntb--;
		}
		cntc=n;
		cnta=cntb=0;
		while(cntc>(n/2)){
			sumc-=c[cntc].fi;
			int now=c[cntc].se;
			if(bb[now]>aa[now]){
				if(cntb<(n/2)){
					cntb++;
					sumc+=bb[now];
				}else{
					cnta++;
					sumc+=aa[now];
				}
			}else if(bb[now]<aa[now]){
				if(cnta>=(n/2)){
					cntb++;
					sumc+=bb[now];
				}else{
					cnta++;
					sumc+=aa[now];
				}
			}else{
				sumc+=bb[now];
				if(cnta>cntb){
					cntb++;					
				}else{
					cnta++;
				}
			}
			cntc--;
		}
	cout<<max(max(suma,sumb),sumc)<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}