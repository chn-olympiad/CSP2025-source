#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n;
struct node{
	int s,id;
}a[100010],b[100010],c[100010];
int cnta,cntb,cntc;
int maxn[100010];
int minn[100010];
int id[100010];
int m[100010];
bool cmp2(int a,int b){
	return m[a]>m[b];
}
int ans=0;
void solve(){
	cin>>n;
	int x,y,z;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>b[i].s>>c[i].s;
		a[i].id=b[i].id=c[i].id=id[i]=i;
		maxn[i]=max(a[i].s,max(b[i].s,c[i].s));
//		minn[i]=min(a[i].s,min(b[i].s,c[i].s));
//		m[i]=(a[i].s-b[i].s)*;
		if(a[i].s>b[i].s){
			if(b[i].s>c[i].s){
				m[i]=a[i].s-b[i].s;
			}else if(c[i].s>a[i].s){
				m[i]=c[i].s-a[i].s;
			}else{
				m[i]=a[i].s-c[i].s;
			}
		}else{
			if(b[i].s<c[i].s){
				m[i]=c[i].s-b[i].s;
			}else if(c[i].s<a[i].s){
				m[i]=b[i].s-a[i].s;
			}else{
				m[i]=b[i].s-c[i].s;
			}
		}
	}
	sort(id+1,id+n+1,cmp2);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(maxn[id[i]]==a[id[i]].s){
			if(cnta>=n/2){
				if(b[id[i]].s>c[id[i]].s){
					cntb++;
					ans+=b[id[i]].s;
				}else if(b[id[i]].s<c[id[i]].s){
					cntc++;
					ans+=c[id[i]].s;
				}else{
					if(cntc<cntb) cntc++;
					else cntb++;
					ans+=c[id[i]].s;
				}
			}else{
				cnta++;
				ans+=a[id[i]].s;
			}
		}
		if(maxn[id[i]]==b[id[i]].s){
			if(cntb>=n/2){
				if(a[id[i]].s>c[id[i]].s){
					cnta++;
					ans+=a[id[i]].s;
				}else if(a[id[i]].s<c[id[i]].s){
					cntc++;
					ans+=c[id[i]].s;
				}else{
					if(cntc<cnta) cntc++;
					else cnta++;
					ans+=c[id[i]].s;
				}
			}else{
				cntb++;
				ans+=b[id[i]].s;
			}
		}
		if(maxn[id[i]]==c[id[i]].s){
			if(cntc>=n/2){
				if(a[id[i]].s>b[id[i]].s){
					cnta++;
					ans+=a[id[i]].s;
				}else if(a[id[i]].s<b[id[i]].s){
					cntb++;
					ans+=b[id[i]].s;
				}else{
					if(cnta<cntb) cnta++;
					else cntb++;
					ans+=a[id[i]].s;
				}
			}else{
				cntc++;
				ans+=c[id[i]].s;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		solve();
		cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			maxn[i]=m[i]=minn[i]=id[i]=a[i].s=b[i].s=c[i].s=0;
		}
	}
} 
