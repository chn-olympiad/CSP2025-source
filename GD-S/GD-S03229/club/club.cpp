#include<bits/stdc++.h>
#define int long long
using namespace std; 
void init(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int T,i;
int n,ans;
int pa,pb,pc;
bool ma,mb,mc;
struct az{
	int a,b,c,zd;
}pe[100001];
int am,bm,cm;
int qh[100001];
void solve(){
	cin>>n;
	ans=0;
	ma=mb=mc=0;
	pa=pb=pc=0;
	am=bm=cm=0;
	for(int i=1;i<=n;i++){
		qh[i]=0;
		cin>>pe[i].a>>pe[i].b>>pe[i].c;
		pe[i].zd=max({pe[i].a,pe[i].b,pe[i].c});
		if(pe[i].zd==pe[i].a){
			am++;
		}
		if(pe[i].zd==pe[i].b){
			bm++;
		}
		if(pe[i].zd==pe[i].c){
			cm++;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=max({pe[i].a,pe[i].b,pe[i].c});
	}
	if(am<=n/2 && bm<=n/2 && cm<=n/2){
		cout<<ans<<"\n";
		return ;
	}
	int cnt=0;
	if(am>n/2){
		for(int i=1;i<=n;i++){
			if(pe[i].zd==pe[i].a){
				qh[++cnt]=min(pe[i].a-pe[i].b,pe[i].a-pe[i].c);
			}
		}
		sort(qh+1,qh+cnt+1);
		for(int i=1;i<=am-n/2;i++){
			ans-=qh[i];
		}
	}
	else if(bm>n/2){
		for(int i=1;i<=n;i++){
			if(pe[i].zd==pe[i].b){
				qh[++cnt]=min(pe[i].b-pe[i].a,pe[i].b-pe[i].c);
			}
		}
		sort(qh+1,qh+cnt+1);
		for(int i=1;i<=bm-n/2;i++){
			ans-=qh[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(pe[i].zd==pe[i].c){
				qh[++cnt]=min(pe[i].c-pe[i].b,pe[i].c-pe[i].a);
			}
		}
		sort(qh+1,qh+cnt+1);
		for(int i=1;i<=cm-n/2;i++){
			ans-=qh[i];
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	init();
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
