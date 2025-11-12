#include<bits/stdc++.h>
#define ll long long
//password Ren5Jie4Di4Ling5%
using namespace std;
const int M=1e6+10;
struct Mem{
	ll a,b,c;
	ll aa,bb,cc;
}mb[4][M];
ll ans=0;
bool cmp1(Mem x,Mem y){
	return x.aa<y.aa;
}
bool cmp2(Mem x,Mem y){
	return x.bb<y.bb;
}
bool cmp3(Mem x,Mem y){
	return x.cc<y.cc;
}
int n,hd[10];
bool vis[10];
void dealw1(int x){
	ll u1=mb[x][hd[x]].b,u2=mb[x][hd[x]].c;
	sort(mb[x]+1,mb[x]+hd[x]+1,cmp1);
	int v;
	if(u1>=u2&&!vis[2]) v=2;else v=3;
	ans+=mb[x][hd[x]].aa;
	mb[v][++hd[v]]=mb[x][hd[x]--];
}
void dealw2(int x){
	ll u1=mb[x][hd[x]].a,u2=mb[x][hd[x]].c;
	sort(mb[x]+1,mb[x]+hd[x]+1,cmp2);
	int v;
	if(u1>=u2&&!vis[1]) v=1;else v=3;
	ans+=mb[x][hd[x]].bb;
	mb[v][++hd[v]]=mb[x][hd[x]--];
}
void dealw3(int x){
	ll u1=mb[x][hd[x]].a,u2=mb[x][hd[x]].b;
	sort(mb[x]+1,mb[x]+hd[x]+1,cmp3);
	int v;
	if(u1>=u2&&!vis[1]) v=1;else v=2;
	ans+=mb[x][hd[x]].cc;
	mb[v][++hd[v]]=mb[x][hd[x]--];
}
void manage(int x){
	while(hd[x]>n/2){
		if(x==1) dealw1(x);
		if(x==2) dealw2(x);
		if(x==3) dealw3(x);
	}
}
int main(){
	//freopen!!!!!!!!!!!!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;hd[1]=hd[2]=hd[3]=0;
		memset(mb,0,sizeof(mb));
		memset(vis,0,sizeof(vis));
		int i,j;
		cin>>n;
		for(i=1;i<=n;i++){
			ll a,b,c,aa,bb,cc,mx=-1;
			cin>>a>>b>>c;
			aa=max(b,c)-a;
			bb=max(a,c)-b;
			cc=max(a,b)-c;
			mx=max(a,max(b,c));
			ans+=mx;
			if(mx==a) mb[1][++hd[1]]={a,b,c,aa,bb,cc};
			else if(mx==b) mb[2][++hd[2]]={a,b,c,aa,bb,cc};
			else if(mx==c) mb[3][++hd[3]]={a,b,c,aa,bb,cc};
		}
		int cnt=2;
		while(cnt--){
			sort(mb[1]+1,mb[1]+hd[1]+1,cmp1);sort(mb[2]+1,mb[2]+hd[2]+1,cmp2);sort(mb[3]+1,mb[3]+hd[3]+1,cmp3);
			for(j=1;j<=3;j++){
				if(!vis[j]&&hd[j]>n/2){
					vis[j]=1;
					manage(j);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
