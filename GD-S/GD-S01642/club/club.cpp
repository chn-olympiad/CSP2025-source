#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int a,b,c,id;
}a[200005],b[200005],c[200005];
bool cmpa(node a,node b){
	return a.a>b.a;
}
bool cmpb(node a,node b){
	return a.b>b.b;
}
bool cmpc(node a,node b){
	return a.c>b.c;
}
bool vis[200005];
void solve(){
	int n,sum=0,ans=0;
	int t[4]={0};
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].id=i;
		b[i]=c[i]=a[i];
	}
	sort(a+1,a+1+n,cmpa);
	sort(b+1,b+1+n,cmpb);
	sort(c+1,c+1+n,cmpc);
	for(int i=1;i<=n;++i){
		int maxn=max(a[i].a,max(b[i].b,c[i].c));
		if(maxn==a[i].a){
			if(t[1]<n/2 && vis[a[i].id]==0){
				ans+=a[i].a;
				t[1]++;
				vis[a[i].id]=1;
			}
			a[i].a=-1;
			maxn=max(b[i].b,c[i].c);
		}
		if(maxn==b[i].b){
			if(t[2]<n/2 && vis[b[i].id]==0){
				ans+=b[i].b;
				t[2]++;
				vis[b[i].id]=1;
			}
			b[i].b=-1;
			maxn=max(a[i].a,c[i].c);
		}
		if(maxn==c[i].c){
			if(t[3]<n/2 && vis[c[i].id]==0){
				ans+=c[i].c;
				t[3]++;
				vis[c[i].id]=1;
			}
			c[i].c=-1;
			maxn=max(a[i].a,b[i].b);
		}
		if(maxn==a[i].a){
			if(t[1]<n/2 && vis[a[i].id]==0){
				ans+=a[i].a;
				t[1]++;
				vis[a[i].id]=1;
			}
			a[i].a=-1;
			maxn=max(b[i].b,c[i].c);
		}
		if(maxn==b[i].b){
			if(t[2]<n/2 && vis[b[i].id]==0){
				ans+=b[i].b;
				t[2]++;
				vis[b[i].id]=1;
			}
			b[i].b=-1;
			maxn=max(a[i].a,c[i].c);
		}
		if(maxn==c[i].c){
			if(t[3]<n/2 && vis[c[i].id]==0){
				ans+=c[i].c;
				t[3]++;
				vis[c[i].id]=1;
			}
			c[i].c=-1;
			maxn=max(a[i].a,b[i].b);
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i)vis[i]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
