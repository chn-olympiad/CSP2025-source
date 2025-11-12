#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
	int u;
	int v;
	int w;
}e[5000010];
int c[20];
int a[20][10010];
int b[20];
bool ch(edge x,edge y){
	return x.w<y.w;
}
int f[10010];
int find1(int q){
	if(f[q]==q){
		return q;
	}
	int t=find1(f[q]);
	f[q]=t;
	return t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int t=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				t=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(j==t){
				continue;
			}
			else{
				e[++cnt].u=j;
				e[cnt].v=t;
				e[cnt].w=a[i][j];
			}
		}
	}
	sort(e+1,e+1+cnt,ch);
	int ans=0;
	int step=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		int u1=find1(u);
		int v1=find1(v);
		if(u1!=v1){
			f[u1]=v1;
			ans+=w;
			step++;
		}
		if(step==n-1){
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
