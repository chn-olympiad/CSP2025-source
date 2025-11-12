#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
const int maxm=20010;
int n;
int bumen[maxn][4],rs[4],ls[maxn];
int maxr;

struct mem{
	int a[4];
	int zd,mdm,zx;
}m[maxn];

int read();

void solve();
void otptans();

int gtzd(int i);
int gtmdm(int i);
int gtzx(int i);

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)solve();
	
	
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		m[i].a[1]=read();
		m[i].a[2]=read();
		m[i].a[3]=read();
		m[i].zd=gtzd(i);
		m[i].zx=gtzx(i);
		m[i].mdm=gtmdm(i);
	}
	maxr=n/2;
	rs[1]=0;
	rs[2]=0;
	rs[3]=0;
	for(int i=1;i<=n;i++){
		bumen[++rs[m[i].zd]][m[i].zd]=i;
	}
	otptans();
	return;
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		c=getchar();
		if(c=='-')f=-1;
	}
	while(c>='0' and c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int gtzd(int i){
	if(m[i].a[1]>=m[i].a[2] and m[i].a[1]>=m[i].a[3])return 1;
	if(m[i].a[2]>=m[i].a[1] and m[i].a[2]>=m[i].a[3])return 2;
	return 3;
}
int gtmdm(int i){
	if(6-m[i].zd-m[i].zx==2)return 2;
	if(6-m[i].zd-m[i].zx==1)return 1;
	return 3;
}
int gtzx(int i){
	if(m[i].a[3]<=m[i].a[2] and m[i].a[3]<=m[i].a[1])return 3;
	if(m[i].a[2]<=m[i].a[1] and m[i].a[2]<=m[i].a[3])return 2;
	return 1;
}
void bstotpt(){
	int tmpa=0,tmpb=0,tmpc=0,ans=0;
	for(int i=1;i<=rs[1];i++)tmpa+=m[bumen[i][1]].a[1];
	for(int i=1;i<=rs[2];i++)tmpb+=m[bumen[i][2]].a[2];
	for(int i=1;i<=rs[3];i++)tmpc+=m[bumen[i][3]].a[3];
	ans=tmpa+tmpb+tmpc;
	cout<<ans<<endl;
	return;
}
void otptans(){
	if(rs[1]<=maxr and rs[2]<=maxr and rs[3]<=maxr){
		bstotpt();
		return;
	}
	if(n==2){
		if(rs[1]!=2 and rs[2]!=2 and rs[3]!=2){
			bstotpt();
			return;
		}
		cout<<max(m[1].a[m[1].zd]+m[2].a[m[2].mdm],m[2].a[m[2].zd]+m[1].a[m[1].mdm])<<endl;
		return;
	}
	int cnt=0,rear=0;
	for(int i=1;i<=n;i++){
		int tmp=m[i].a[1]+m[i].a[2]+m[i].a[3];
		if(m[i].a[1]==tmp or m[i].a[2]==tmp or m[i].a[3]==tmp){
			cnt++;
			ls[++rear]=tmp;
		}
	}
	if(cnt==n){
		sort(ls+1,ls+n+1);
		int ans=0;
		for(int i=1;i<=maxr;i++){
			ans+=ls[n-i+1];
		}
		cout<<ans<<endl;
		return;
	}
	bstotpt();
	return;
}

