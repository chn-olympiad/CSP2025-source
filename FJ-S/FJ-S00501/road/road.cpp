#include<bits/stdc++.h>
using namespace std;
struct t{
	int u,v,w;
}e[1000001],ee[100001];
int n,m,k,u,v,w,sum,ans=1e9,top,cnt;
int a[11][10001],c[11];
int f[10001];
bool cmp(t a,t b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
		sum=0,top=0,cnt=1;
		for(int j=1;j<=n;j++) f[j]=j;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				sum+=c[j];
				for(int o=1;o<=n;o++){
					ee[++top].u=j,ee[top].v=o,ee[top].w=a[j][o];
				}
			}
		}
		if(sum>=ans) continue;
		sort(ee+1,ee+1+top,cmp);
		for(int o=1,j=1;o<=m||j<=top;){
			if((e[o].w<ee[j].w||j>=top)&&o<m){
				int q=find(e[o].u),p=find(e[o].v);
				if(q!=p){
					sum+=e[o].w;
					cnt++;
					f[q]=p;
				}
				o++;
			}else{
				int q=find(ee[j].u),p=find(ee[j].v);
				if(q!=p){
					sum+=ee[j].w;
					cnt++;
					f[q]=p;
				}
				j++;
			}
			if(cnt==n) break;
		}
		if(cnt==n) ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

