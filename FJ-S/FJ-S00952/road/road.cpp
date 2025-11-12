#include<bits/stdc++.h>
#define N 5000005
using namespace std;
const int mod=10000009;
int n,m,k,cnt,f[N],c[10005];
long long ans,op=0,ans1=0;
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
struct node{
	int u,v,w;
}a[N];
void add(int u,int v,int w){
	a[++cnt]=node{u,v,w};
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=2*n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		add(u,v,w);
	}
	sort(a+1,a+cnt+1,cmp);
	int sum=0,l=n;
	for(int i=1;i<=cnt;i++){
		int q=find(a[i].u),w=find(a[i].v);
		if(q!=w){
			f[q]=w;
			sum++;
			ans+=a[i].w;
			if(sum==n-1) break;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[j];
		}
		if(c[0]>ans) continue;
		ans1+=c[0];
		l++;
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				add(j,k,c[j]+c[k]);
			}
		}
		sum=0;op=0;
		sort(a+1,a+cnt+1,cmp);
		for(int j=1;j<=2*n;j++) f[j]=j;
		for(int j=1;j<=cnt;j++){
			int q=find(a[j].u),w=find(a[j].v);
			if(q!=w){
				f[q]=w;
				sum++;
				op+=a[j].w;
				if(sum==l-1) break;
			}
		}
		ans=min(op+ans1,ans);
	}
	cout<<ans;
	return 0;
}
