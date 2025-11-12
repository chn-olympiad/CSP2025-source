#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10,M = 2e4+10;
int n; 
int cta[M],ctb[M],ctc[M];
struct node{
	int a,b,c;
}a[N];
struct type{
	int id,cz;
};
void ga(){
	for(int i = 0;i<M;i++){
		cta[i] = ctb[i] = ctc[i] = 0;
	} 
	cin>>n;
	long long mxn = n/2,ans = 0;
	int cnta = 0,cntb = 0,cntc = 0; 
	for(int i = 1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		int mx = max({a[i].a,a[i].b,a[i].c});
		ans+=mx;
		if(a[i].a==mx){
			cnta++;
			if(a[i].b>a[i].c){
				cta[a[i].a-a[i].b]++;
			}else{
				cta[a[i].a-a[i].c]++;
			}
		}else if(a[i].b==mx){
			cntb++;
			if(a[i].a>a[i].c){
				ctb[a[i].b-a[i].a]++;
			}else{
				ctb[a[i].b-a[i].c]++;
			}
		}else if(a[i].c==mx){
			cntc++;
			if(a[i].a>a[i].b){
				ctc[a[i].c-a[i].a]++;
			}else{
				ctc[a[i].c-a[i].b]++;
			}
		}
	}
	if(cnta>mxn){
		for(int i = 0;i<M&&cnta>mxn;i++){
			while(cta[i]>0){
				ans-=i;
				cta[i]--;
				cnta--;
			}
		}
	}else if(cntb>mxn){
		for(int i = 0;i<M&&cntb>mxn;i++){
			while(ctb[i]>0){
				ans-=i;
				ctb[i]--;
				cntb--;
			}
		}
	}else if(cntc>mxn){
		for(int i = 0;i<M&&cntc>mxn;i++){
			while(ctc[i]>0){
				ans-=i;
				ctc[i]--;
				cntc--;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		ga();
	}
	return 0;
} 
