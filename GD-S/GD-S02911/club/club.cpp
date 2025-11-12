#include<bits/stdc++.h>
#define N 100010
#define pii pair<int,int>
#define rint register int
using namespace std;
inline int read() {
	char c;
	int num_in=0,num_sign=1;
	for(; !isdigit(c); c=getchar())
		if(c=='-') num_sign=-1;
	for(; isdigit(c); c=getchar())
		num_in=(num_in<<3)+(num_in<<1)+(c^48);
	return num_in*num_sign;
}
int T,n,ans=0;
bool v[N];
int a[N][4];
priority_queue<pii,vector<pii>,less<pii> > q;
priority_queue<pii,vector<pii>,greater<pii> > cl[4];
bool jg(int c){
	if(c<=(n/2)) return true;
	else return false;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int x,y,z;
	T=read();
	while(T--){
		ans=0;
		memset(v,false,sizeof(v));
		memset(a,0,sizeof(a));
		for(rint i=1;i<=3;i++) while(!cl[i].empty()) cl[i].pop();
		n=read();
		for(rint i=1;i<=n;i++){
			x=read(),y=read(),z=read();
			a[i][1]=x,a[i][2]=y,a[i][3]=z;
			q.push(make_pair(x,i));
			q.push(make_pair(y,i));
			q.push(make_pair(z,i));
		}
		while(!q.empty()){
			x=q.top().first,y=q.top().second;
			q.pop();
			if(v[y]) continue;
			for(rint i=1;i<=3;i++){
				if(a[y][i]==x){
					if(jg(cl[i].size()+1)){
						cl[i].push(make_pair(x,y));
						v[y]=true;
						ans+=x;
					} else{
						int o,p,maxn=0,j=0;
						o=cl[i].top().first,p=cl[i].top().second;
						for(j=1;j<=3;j++)
							if(jg(cl[j].size()+1)&&i!=j) maxn=max(maxn,a[p][j]);
						if(maxn+a[y][i]>o){
							ans+=(maxn+a[y][i]-o);
							v[y]=true;
							cl[i].pop();
							cl[i].push(make_pair(x,y));
							cl[j].push(make_pair(o,p));
						}
					}
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
