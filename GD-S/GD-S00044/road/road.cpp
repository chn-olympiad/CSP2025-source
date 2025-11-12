#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
struct node{
	int u,v,w;
	bool operator < (const node& x) const {
		return w<x.w;
	}
};
node a[10000000];
bool cmp(node t1,node t2) {
	return t1.w<t2.w;
}
int root[100005];
int c[10];
int v[10][10005];
set<node> st;
int find(int o) {
	if(root[o]==o) return o;
	return root[o]=find(root[o]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) {
		a[i].u=read(),a[i].v=read(),a[i].w=read();
		st.insert(node{a[i].u,a[i].v,a[i].w});
	}
	set<node>::iterator it;
	for(it=st.begin();it!=st.end();it++) {
		node t=*it;
		cout<<t.u<<" "<<t.v<<" "<<t.w<<endl;
	} 
	bool flagA=true;
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			v[i][j]=read();
		}
	}
	if(flagA) {
		cout<<1;
		int temp=m,ans=1e18;
		int S=(1<<k)-1;
		int sum=0,q=0;
		m=temp;
		for(int i=1;i<=k;i++) {
			if(S & (1<<(i-1))) {
				sum+=c[i],q++;
				for(int j=1;j<=n;j++) {
//					m++;
//					a[m].u=n+i,a[m].v=j,a[m].w=v[i][j];
					st.insert(node{n+i,j,v[i][j]});
				}
			}
		}
//		cout<<q<<" ";
		for(int i=1;i<=2*n;i++) root[i]=i;
//		sort(a+1,a+m+1);
		int cnt=0;
		for(it=st.begin();it!=st.end();it++) {
//		for(int i=1;i<=m;i++) {
			node t=*it;
			int x=find(t.u),y=find(t.v);
			if(x!=y) {
				root[x]=y;
				cnt++;
				sum+=t.w;
			}
//			if(cnt==(n+q-1)) break;
		}
		for(int i=1;i<=k;i++) {
			if(S & (1<<(i-1))) {
				for(int j=1;j<=n;j++) {
					st.erase(node{n+i,j,v[i][j]});
				}
			}
		}
		ans=min(ans,sum);
	}
	int temp=m,ans=1e18;
	for(int S=0;S<(1<<k);S++) {
		int sum=0,q=0;
		m=temp;
		for(int i=1;i<=k;i++) {
			if(S & (1<<(i-1))) {
				sum+=c[i],q++;
				for(int j=1;j<=n;j++) {
//					m++;
//					a[m].u=n+i,a[m].v=j,a[m].w=v[i][j];
					st.insert(node{n+i,j,v[i][j]});
				}
			}
		}
//		cout<<q<<" ";
		for(int i=1;i<=2*n;i++) root[i]=i;
//		sort(a+1,a+m+1);
		int cnt=0;
		for(it=st.begin();it!=st.end();it++) {
//		for(int i=1;i<=m;i++) {
			node t=*it;
			int x=find(t.u),y=find(t.v);
			if(x!=y) {
				root[x]=y;
				cnt++;
				sum+=t.w;
			}
//			if(cnt==(n+q-1)) break;
		}
		for(int i=1;i<=k;i++) {
			if(S & (1<<(i-1))) {
				for(int j=1;j<=n;j++) {
					st.erase(node{n+i,j,v[i][j]});
				}
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
