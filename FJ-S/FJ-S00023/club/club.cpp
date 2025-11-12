#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=1e5+2;
int n,sum[5],tot,Up;
int a[N][5],su[N],ans,vs[N];
struct Ed{
	int w,id,clu;
}b[N*6];
bool cmp(Ed u,Ed v){
	return u.w>v.w;
}
priority_queue <int> q[5];
void pd(){
	for(int i=1;i<=3;++i)while(q[i].size())q[i].pop();
	for(int i=1;i<=tot;++i){
		int w=b[i].w;
		int id=b[i].id;
		int clu=b[i].clu;
		if(vs[id])continue;
		
		if(q[clu].size()<Up){
			ans+=w;
			q[clu].push(su[id]);
			vs[id]=1;
		}else{
			int x=q[clu].top();
			if(x>=su[id]){
				q[clu].pop();
				ans+=x+w;
				q[clu].push(su[id]);
				vs[id]=1;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
void solve(){
	n=read();
	tot=ans=0;
	Up=n/2;
	for(int i=1;i<=n;++i){
		vs[i]=0;
		a[i][1]=read();a[i][2]=read();a[i][3]=read();
		int ma=0,cm=0;
		for(int j=1;j<=3;++j){
			if(a[i][j]>ma)cm=ma,ma=a[i][j];
			else if(a[i][j]>cm)cm=a[i][j];
		}
		su[i]= -ma+cm;
		
		b[++tot]={a[i][1],i,1};
		b[++tot]={a[i][2],i,2};
		b[++tot]={a[i][3],i,3};
	}
	sort(b+1,b+1+tot,cmp);
	pd();
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt=read();while(ttt--)solve();
	return 0;
}
