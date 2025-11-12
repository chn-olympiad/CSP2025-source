#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int T,n,sum1,sum2,sum3,tot,tot2;
long long ans=0;
long long mx=-2e9;
struct node{
	int a,b,c,qa,qb,qc;
}p[100005],c[100005];
struct tip{
	int id,num;
}t[100005],t2[100005];
bool cmp(node x,node y){
	if(x.qa!=y.qa)return x.qa>y.qa;
	if(x.qb!=y.qb)return x.qb>y.qb;
	return x.qc>y.qc;
	}
bool cmp2(node x,node y){
	return x.a-x.b>y.a-y.b;}
bool cmp3(tip x,tip y){
	if(x.num!=y.num)return x.num<y.num;
	if(x.num==1){
		if(p[x.id].qb!=p[y.id].qb)return p[x.id].qb>p[y.id].qb;
		return p[x.id].qc>p[y.id].qc;}
	if(x.num==2){
		if(p[x.id].qc!=p[y.id].qc)return p[x.id].qc>p[y.id].qc;
		return p[x.id].qa>p[y.id].qa;}
	if(x.num==3){
		if(p[x.id].qa!=p[y.id].qa)return p[x.id].qa>p[y.id].qa;
		return p[x.id].qb>p[y.id].qb;}}
bool cmp4(tip x,tip y){
	if(x.num!=y.num)return x.num<y.num;
	if(x.num==1){return p[x.id].qa>p[y.id].qa;}
	if(x.num==2){return p[x.id].qb>p[y.id].qb;}
	if(x.num==3){return p[x.id].qc>p[y.id].qc;}}
void dfs(int x);
void solve1();
void solve2();
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		sum1=0,sum2=0,sum3=0,ans=0,mx=-2e9,tot=0,tot2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			p[i].qa=p[i].a*2-p[i].b-p[i].c;
			p[i].qb=p[i].b*2-p[i].a-p[i].c;
			p[i].qc=0-p[i].qa-p[i].qb;
		}
		for(int i=1;i<=n;i++)if(p[i].c==0)cnt++;
		if(cnt==n)solve1();
		else if(n<=10){
			dfs(1);
			cout<<mx<<"\n";}
		else solve2(); 
	}
	return 0;
}
void solve1(){
	sort(p+1,p+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans+=p[i].a;
		else ans+=p[i].b;
	}
	cout<<ans<<"\n";} 
void solve2(){
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(p[i].qa>=p[i].qb&&p[i].qa>=p[i].qc){
			if(sum1<n/2)ans+=p[i].a,sum1++;
			else {t[++tot].id=i;t[tot].num=1;}}
		else if(p[i].qb>=p[i].qa&&p[i].qb>=p[i].qc){
			if(sum2<n/2)ans+=p[i].b,sum2++;
			else {t[++tot].id=i;t[tot].num=2;}}
		else if(p[i].qc>=p[i].qa&&p[i].qc>=p[i].qb){
			if(sum3<n/2)ans+=p[i].c,sum3++;
			else {t[++tot].id=i;t[tot].num=3;}}
	}
	sort(t+1,t+1+tot,cmp3);
	for(int i=1;i<=tot;i++){
		if(t[i].num==1){
			if(sum2<n/2)ans+=p[t[i].id].b,sum2++;
			else t2[++tot2].id=t[i].id,t2[tot2].num=3;}
		else if(t[i].num==2){
			if(sum3<n/2)ans+=p[t[i].id].c,sum3++;
			else t2[++tot2].id=t[i].id,t2[tot2].num=1;}
		else if(t[i].num==3){
			if(sum1<n/2)ans+=p[t[i].id].a,sum1++;
			else t2[++tot2].id=t[i].id,t2[tot2].num=2;}}
	sort(t2+1,t2+1+tot2,cmp4);
	for(int i=1;i<=tot2;i++){
		if(t2[i].num==2)ans+=p[t2[i].id].b;
		else if(t2[i].num==3)ans+=p[t2[i].id].c;
		else if(t2[i].num==1)ans+=p[t2[i].id].a;
		}
	cout<<ans<<"\n";
}
void dfs(int x){
	if(x>n){
		mx=max(mx,ans);
		return;}
	if(sum1<n/2){
		ans+=p[x].a;sum1++;
		dfs(x+1);
		ans-=p[x].a;sum1--;}
	if(sum2<n/2){
		ans+=p[x].b;sum2++;
		dfs(x+1);
		ans-=p[x].b;sum2--;}
	if(sum3<n/2){
		ans+=p[x].c;sum3++;
		dfs(x+1);
		ans-=p[x].c;sum3--;}
	return;}
