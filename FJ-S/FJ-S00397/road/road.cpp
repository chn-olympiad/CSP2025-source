#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int MAXN=1E4+10,MAXM=3*1E6+10;
int f[MAXN],c[12],t[MAXN];
struct edge {
	int u,v,w;
} e[MAXM];
int cnt=0,ans=0;
int n,m,k;
int find(int x) {
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void join(int x,int y) {
	x=find(x);
	y=find(y);
	if(x!=y) {
		f[x]=y;
	}
}
bool cmp(edge x,edge y) {
	return x.w<y.w;
}
void kruscal() {
	sort(e+1,e+cnt+1,cmp);
	int cnt2=0;
	fo(i,1,cnt) {
		if(cnt2>=n) {
			break;
		}
		int x=e[i].u,y=e[i].v;
//		cout<<"check"<<x<<' '<<y<<'\n';
		if(find(x)!=find(y)) {
//			cout<<"join "<<x<<' '<<y<<'\n';
			cnt2++;
			join(x,y);
			ans+=e[i].w;
		}
	}
	cout<<ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	fo(i,1,n) {
		f[i]=i;
	}
	fo(i,1,m) {
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cnt=m;
	if(k!=0) {
		fo(i,1,k) {
			int q;
			cin>>c[i];
			fo(j,1,n) {
				cin>>t[j];
				if(t[j]==0) {
					q=j;
				}
			}
			fo(j,1,n) {
				bool flag=0;
				int eid;
				if(j==q)continue;
				fo(k,1,n) {
					if(e[k].u==q and e[k].v==j) {
						flag=1;
						eid=k;
						break;
					}
				}
				if(flag) {
					e[eid].w=min(e[eid].w,t[j]);
				} else {
					cnt++;
					e[cnt].u=q,e[cnt].v=j,e[cnt].w=t[j];
				}
			}
		}
		kruscal();
	} else {
		kruscal();
	}
	return 0;
}
