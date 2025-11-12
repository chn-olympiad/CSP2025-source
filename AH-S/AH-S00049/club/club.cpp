#include <bits/stdc++.h>
using namespace std;
const int max_=1e5+5;
int n,s[4];
struct node{
	int x,pos;
}a[max_][4];
struct qwq{
	int a,b,c,pa,pb,pc;
}f[max_];
bool vis[max_];
int gyf(qwq x,int t){
	if(t==1){
		return x.a;
	}else if(t==2){
		return x.b;
	}else{
		return x.c;
	}
}
int pgyf(qwq x,int t){
	if(t==1){
		return x.pa;
	}else if(t==2){
		return x.pb;
	}else{
		return x.pc;
	}
}
void debug(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cout<<gyf(f[i],j)<<' ';
		}
		cout<<'\n';
	}
}
void solve(){
	memset(s,0,sizeof(s));
	memset(vis,0,sizeof(vis));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j].x;
			a[i][j].pos=j;
		}
		sort(a[i]+1,a[i]+4,[&](node x,node y){
			return x.x>y.x;
		});
	}
	for(int i=1;i<=n;i++){
		f[i].a=a[i][1].x;
		f[i].b=a[i][2].x;
		f[i].c=a[i][3].x;
		f[i].pa=a[i][1].pos;
		f[i].pb=a[i][2].pos;
		f[i].pc=a[i][3].pos;
	}
	sort(f+1,f+n+1,[&](qwq x,qwq y){
		if(x.a!=y.a){
			return x.a>y.a;
		}else if(x.b!=y.b){
			return x.b>y.b;
		}else{
			return x.c>y.c;
		}
	});
	int t=0,ans=0,rp=n/2;
	vector<int>v[4];
	for(int i=1;i<=n;i++){
		++s[pgyf(f[i],1)];
		ans+=gyf(f[i],1);
		v[pgyf(f[i],1)].push_back(i);
	}
	if(s[1]>rp){
		sort(v[1].begin(),v[1].end(),[&](int x,int y){
			return (gyf(f[x],1)-gyf(f[x],2))<(gyf(f[y],1)-gyf(f[y],2));
		});
		int aaa=s[1]-rp;
		for(int i=0;i<aaa;i++){
			int now=v[1][i];
			v[pgyf(f[now],2)].push_back(now);
			--s[pgyf(f[now],1)];
			++s[pgyf(f[now],2)];
			ans-=(gyf(f[now],1)-gyf(f[now],2));
		}
	}else if(s[2]>rp){
		sort(v[2].begin(),v[2].end(),[&](int x,int y){
			return (gyf(f[x],1)-gyf(f[x],2))<(gyf(f[y],1)-gyf(f[y],2));
		});
		int aaa=s[2]-rp;
		for(int i=0;i<aaa;i++){
			int now=v[2][i];
			--s[pgyf(f[now],1)];
			++s[pgyf(f[now],2)];
			ans-=(gyf(f[now],1)-gyf(f[now],2));
		}
	}else{
		sort(v[3].begin(),v[3].end(),[&](int x,int y){
			return (gyf(f[x],1)-gyf(f[x],2))<(gyf(f[y],1)-gyf(f[y],2));
		});
		int aaa=s[3]-rp;
		for(int i=0;i<aaa;i++){
			int now=v[3][i];
			--s[pgyf(f[now],1)];
			++s[pgyf(f[now],2)];
			ans-=(gyf(f[now],1)-gyf(f[now],2));
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}