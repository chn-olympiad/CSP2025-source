#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int t,n,tii,bm[10];
ll maxn;
bool bz=1,cz=1;
struct cpz{
	int a,b,c,sm,tc,xz,xb;
}cp[N];
bool cmp(cpz aa,cpz bb){
	return aa.a>bb.a;
}
bool bcmp(cpz aa,cpz bb){
	return aa.a>bb.a;
}
bool cmpz(cpz aa,cpz bb){
	if(aa.sm!=bb.sm)return aa.sm>bb.sm;
	return aa.c<bb.c;
}
bool tcmp(cpz aa,cpz bb){
	if(aa.tc!=bb.tc)return aa.tc<bb.tc;
	return aa.b>bb.b;
}
void dfs(int ca,int cb,int cc,int p,ll ans){
	int hn=n/2;
	if(ca>hn||cb>hn||cc>hn){
		return;
	}
	if(p>n){
		maxn=max(maxn,ans);
		return;
	}	
	dfs(ca+1,cb,cc,p+1,ans+cp[p].a);
	dfs(ca,cb+1,cc,p+1,ans+cp[p].b);
	dfs(ca,cb,cc+1,p+1,ans+cp[p].c);
	return;
}
int main(){
//	freopen("club2.in","r",stdin);
//	freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		maxn=0;
		tii=0;
		bz=1;
		cz=1;
		memset(cp,0,sizeof(cp));
		memset(bm,0,sizeof(bm)); 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cp[i].a>>cp[i].b>>cp[i].c;
			if(cp[i].b!=0)bz=0;
			if(cp[i].c!=0)cz=0;
		}
		if(bz&&cz){
			sort(cp+1,cp+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				maxn+=cp[i].a;
			}
			cout<<maxn<<"\n";
			continue;
		}
		else if(cz){
			for(int i=1;i<=n;i++){
				cp[i].sm=cp[i].a-cp[i].b;
			}
			sort(cp+1,cp+1+n,cmpz);
			for(int i=1;i<=n/2;i++){
				maxn+=cp[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				maxn+=cp[i].b;
			}
			cout<<maxn<<"\n";
		}
		else if(n<=15){
			dfs(0,0,0,1,0);
			cout<<maxn<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				cp[i].sm=cp[i].a-cp[i].b;
			}
			sort(cp+1,cp+1+n,cmpz);
			for(int i=1;i<=n/2;i++){
				cp[i].xz=cp[i].a;
				cp[i].xb=1;
				bm[1]++;
			}
			for(int i=n/2+1;i<=n;i++){
				cp[i].xz=cp[i].b;
				cp[i].xb=2;
				bm[2]++;
			}
//			for(int i=1;i<=n;i++){
//				cout<<cp[i].xz<<"\n";
//			}
//			cout<<"\n";
			for(int i=1;i<=n;i++){
				if(cp[i].xz-cp[i].c<=0){
					tii++;
					cp[i].tc=cp[i].xz-cp[i].c;
				}
			}
//			for(int i=1;i<=n;i++){
//				cout<<cp[i].tc<<"\n";
//			}
			sort(cp+1,cp+1+n,tcmp);
			for(int i=1;i<=min(tii,n/2);i++){
//				cout<<cp[i].tc<<"\n";
				bm[cp[i].xb]--;
				cp[i].xz=cp[i].c;
				cp[i].xb=3;
				bm[3]++;
			}
//			cout<<"\n";
			sort(cp+1,cp+1+n,bcmp);
			for(int i=1;i<=n;i++){
				if(n/2-bm[2]==0){
					break;
				}
				if(cp[i].b>cp[i].xz){
					bm[cp[i].xb]--;
					cp[i].xb=2;
					cp[i].xz=cp[i].b;
					bm[2]++;
				}
			}
			sort(cp+1,cp+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(n/2-bm[1]==0){
					break;
				}
				if(cp[i].a>cp[i].xz){
					bm[cp[i].xb]--;
					cp[i].xb=1;
					cp[i].xz=cp[i].a;
					bm[1]++;
				}
			}
			for(int i=1;i<=n;i++){
				maxn+=cp[i].xz;
//				cout<<cp[i].xz<<"\n";
			}
//			cout<<"\n";
//			dfs(0,0,0,1,0);
			cout<<maxn<<"\n";
		}
	}
	return 0;
}
//¾øÍû 
