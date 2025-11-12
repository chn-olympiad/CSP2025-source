#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct bian{
	int a,b,v,la;
};
int n,m,k;
int v[11];
int g[11][10005];
int fa[1025][10005];
bian b[1000005];
bian h[1025][10005];
int cmp(bian a,bian b){
	return a.v<b.v;
}
int ffind(int x,int y){
	if(fa[y][x]==x){
		return x;
	}
	return fa[y][x]=ffind(fa[y][x],y);
}
int ct[1025];
int cnt;
int ans[1025];
int out;
int x[100];
int le;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].a>>b[i].b>>b[i].v;
		b[i].la=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<(1<<k);j++)
			fa[j][i]=i;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
		cnt=0;
		for(int ii=1;ii<=n;ii++){
			for(int jj=ii+1;jj<=n;jj++){
				h[i][++cnt]={ii,jj,
				g[i][ii]+g[i][jj],i};
			}
		}
		sort(h[i]+1,h[i]+cnt+1,cmp);
	}
	sort(b+1,b+m+1,cmp);
	bian so[100];
	for(int i=0;i<=k;i++){x[i]=1;}
	cnt=(1<<k);
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1)))ans[i]+=v[j];
		}
	}
	while(cnt){
		so[0]=b[x[0]];
		le=0;
		for(int i=1;i<=k;i++){
			if(x[i]>n){
				le++;
			}else{
				so[i-le]=h[i][x[i]];
			}
		}
		sort(so+(x[0]>m),so+k+1-le,cmp);
		bian u=so[0];
		x[so[0].la]++;
		for(int i=0;i<(1<<k);i++){
			if(ct[i]==n-1)continue;
			if(u.la==0){
				if(ffind(u.a,i)!=ffind(u.b,i)){
					fa[i][ffind(u.a,i)]=ffind(u.b,i);
					ct[i]++;
					if(ct[i]==n-1)cnt--;
					ans[i]+=u.v;
				}
			}else{
				if(i&(1<<(u.la-1))){
					if(ffind(u.a,i)!=ffind(u.b,i)){
						fa[i][ffind(u.a,i)]=ffind(u.b,i);
						ct[i]++;
						if(ct[i]==n-1)cnt--;
						ans[i]+=u.v;
					}
				}
			}
		}
	}
	out=1e9;
	for(int i=0;i<(1<<k);i++){
		out=min(out,ans[i]);
		//cout<<ans[i]<<endl;
	}
	cout<<out;
	return 0;
}
/*
5 7 2
1 2 1
1 3 7
2 3 2
2 5 4
3 5 6
3 4 4
4 5 2
0 6 6 6 4 4
1 9 9 1 1 9

5 7 0
1 2 1
1 3 7
2 3 2
2 5 4
3 5 6
3 4 4
4 5 2
*/

