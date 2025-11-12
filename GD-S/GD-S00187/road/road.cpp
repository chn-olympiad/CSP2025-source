#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[11],g[11],f[10020],d,ee;
struct r{
	int u,v,w,a;
};
r a[2000001];
bool cmp(r x,r y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
}
void cc(long long e){
	for(int i=0;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=0;i<d;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			if(a[i].a!=0&&g[a[i].a]==0){
				continue;
			}
			f[x]=y;
			e+=a[i].w;
			int h=find(1);
			h=0;
			for(int i=2;i<=n;i++){
				if(find(i)!=f[1]){
					h=1;
					break;
				}
			}
			if(h==0){
				break;
			}
		}
	}
	if(e<ee){
		ee=e;
	}
}
void rr(int aa,long long e){
	if(aa==k+1){
		cc(e);
		return;
	}
	g[aa]=0;
	rr(aa+1,e);
	g[aa]=1;
	e+=c[aa];
	rr(aa+1,e);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].a=0;
	}
	d=m;
	int ff=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			ff=1;
		}
		for(int j=1;j<=n;j++){
			a[d].u=j;
			a[d].v=n+i;
			a[d].a=i;
			cin>>a[d].w;
			if(a[d].w!=0){
				ff=1;
			}
			d++;
		}
	}
	if(ff==0){
		cout<<0;
		return 0;
	}
	ee=2000000000;
	sort(a,a+d,cmp);
	rr(1,0);
	cout<<ee;
	return 0;
} 
