#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int n;
const int N=1e5+7;
struct node{
	int a,b,c;
}q[N];
int cnt=0,ans,w[N];
pii s1[N],s2[N],s3[N];
void solve(){
	n=read();
	ans=0;
	int l1=0,l2=0,l3=0;
	for(int i=1;i<=n;i++)
		q[i]={read(),read(),read()};
	for(int i=1;i<=n;i++){
		int maxx=max(q[i].a,max(q[i].b,q[i].c));
		if(maxx==q[i].a) s1[++l1]=mk(maxx,i);
		else if(maxx==q[i].b) s2[++l2]=mk(maxx,i);
		else s3[++l3]=mk(maxx,i);
		ans+=maxx;
	}
	if(l1>n/2){
		int cntw=0;
		for(int i=1;i<=l1;i++){
			int u=s1[i].se;
			w[++cntw]=s1[i].fi-max(q[u].b,q[u].c);
		}
		sort(w+1,w+cntw+1);
		for(int i=1;i<=l1-n/2;i++) ans-=w[i];
	}
	else if(l2>n/2){
		int cntw=0;
		for(int i=1;i<=l2;i++){
			int u=s2[i].se;
			w[++cntw]=s2[i].fi-max(q[u].a,q[u].c);
		}
		sort(w+1,w+cntw+1);
		for(int i=1;i<=l2-n/2;i++) ans-=w[i];
	}
	else if(l3>n/2){
		int cntw=0;
		for(int i=1;i<=l3;i++){
			int u=s3[i].se;
			w[++cntw]=s3[i].fi-max(q[u].b,q[u].a);
		}
		sort(w+1,w+cntw+1);
		for(int i=1;i<=l3-n/2;i++) ans-=w[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
