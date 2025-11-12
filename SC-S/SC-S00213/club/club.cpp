#include<bits/stdc++.h>
using namespace std;
int t,n,lmax,ansab,ansac,ansba,ansbc,ansca,anscb,ans;
struct REN{
	int a,b,c;
}r[100005];
bool cmpab(REN x,REN y){
	if(x.a!=y.a)return x.a>y.a;
	return x.b<y.b; 
}
bool cmpac(REN x,REN y){
	if(x.a!=y.a)return x.a>y.a;
	return x.c<y.c; 
}
bool cmpba(REN x,REN y){
	if(x.b!=y.b)return x.b>y.b;
	return x.a<y.a;
}
bool cmpbc(REN x,REN y){
	if(x.b!=y.b)return x.b>y.b;
	return x.c<y.c;
}
bool cmpca(REN x,REN y){
	if(x.c!=y.c)return x.c>y.c;
	return x.a<y.a; 
}
bool cmpcb(REN x,REN y){
	if(x.c!=y.c)return x.c>y.c;
	return x.b<y.b; 
}
void dfs(int u,int resa,int resb,int resc,int ka,int kb,int kc){
	if(u==n+1){
		ans=max(ans,resa+resb+resc);
		return;
	}
	if(ka<lmax) dfs(u+1,resa+r[u].a,resb,resc,ka+1,kb,kc);
	if(kb<lmax) dfs(u+1,resa,resb+r[u].b,resc,ka,kb+1,kc);
	if(kc<lmax) dfs(u+1,resa,resb,resc+r[u].c,ka,kb,kc+1);
}
//int dp[100005][5];
//priority_queue<int,vector<int>,greater<int> >q1;
//priority_queue<int,vector<int>,greater<int> >q2;
//priority_queue<int,vector<int>,greater<int> >q3;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		lmax=(n>>1);
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
		}
		if(n<=30){
			ans=0;
			dfs(1,0,0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		sort(r+1,r+n+1,cmpab);
		for(int i=1;i<=lmax;i++){
			ansab+=r[i].a;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].b<r[i].c) ansab+=r[i].c;
			else ansab+=r[i].b;
		}
		sort(r+1,r+n+1,cmpac);
		for(int i=1;i<=lmax;i++){
			ansac+=r[i].a;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].b<r[i].c) ansac+=r[i].c;
			else ansac+=r[i].b;
		}
		ansab=max(ansab,ansac);
		sort(r+1,r+n+1,cmpba);
		for(int i=1;i<=lmax;i++){
			ansba+=r[i].b;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].a<r[i].c) ansba+=r[i].c;
			else ansba+=r[i].a;
		}
		sort(r+1,r+n+1,cmpbc);
		for(int i=1;i<=lmax;i++){
			ansbc+=r[i].b;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].a<r[i].c) ansbc+=r[i].c;
			else ansbc+=r[i].a;
		}
		ansba=max(ansba,ansbc);
		sort(r+1,r+n+1,cmpca);
		for(int i=1;i<=lmax;i++){
			ansca+=r[i].c;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].a<r[i].b) ansca+=r[i].b;
			else ansca+=r[i].a;
		}
		sort(r+1,r+n+1,cmpcb);
		for(int i=1;i<=lmax;i++){
			anscb+=r[i].c;
		}
		for(int i=lmax+1;i<=n;i++){
			if(r[i].a<r[i].b) anscb+=r[i].b;
			else anscb+=r[i].a;
		}
		ansca=max(ansca,anscb);
		cout<<max(ansab,max(ansba,ansca))<<"\n";
		ansab=ansba=ansac=ansca=ansbc=anscb=0;
	}
}