#include<iostream>
#include<algorithm>
#include<cmath>
#define y1 wyyy111
using namespace std;
const int maxn=1e5+15;
int T,n;
struct pe{
	int a,b,c;
//	int ab,bc,ac;
}p[maxn];
long long ans=0;
//bool cmp(pe x,pe y){
//	
//} 
int ua,ub,uc;
void dfs(int now,long long cnt){
	if(now>n){
		ans=max(ans,cnt);
		return;
	}
	if(ua<n/2){
		ua++;
		dfs(now+1,cnt+p[now].a);
//		cout<<now<<' '<<p[now].a<<'\n';
		ua--;
	}
	if(ub<n/2){
		ub++;
		dfs(now+1,cnt+p[now].b);
//		cout<<now<<' '<<p[now].b<<'\n';
		ub--;
	}
	if(uc<n/2){
		uc++;
		dfs(now+1,cnt+p[now].c);
//		cout<<now<<' '<<p[now].c<<'\n';
		uc--;
	}
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		ans=0,ua=0,ub=0,uc=0;
		int anst=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
//			p[i].ab=abs(p[i].a-p[i].b);
//			p[i].bc=abs(p[i].b-p[i].c);
//			p[i].ac=abs(p[i].a-p[i].c);
			anst+=max(p[i].a,max(p[i].b,p[i].c));
		}
//		sort(p+1,p+n+1,cmp);
		if(n>=20){
			cout<<anst<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
	return 0;
}
