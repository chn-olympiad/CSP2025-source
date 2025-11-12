# include<bits/stdc++.h>
using namespace std;
int n,m,k,Fa[10020],siz[10020],N,bz[10020],ipt;
long long c[11],ans=8430738502437568511;
struct ege{int x,y;long long val;}EGE[1000005],Ege[110001];
bool cmp(ege a,ege b){return a.val<b.val;}
int FA(int x){return Fa[x]==x?x:FA(Fa[x]);}
void merge(int x,int y){int a=FA(x),b=FA(y);if(a!=b){if(siz[b]>siz[a])swap(a,b);siz[a]+=siz[b],Fa[b]=a;}}
void sous(int x,long long y){
	if(x==n+k+1){
		for(int i = 1;i<=n+k;i++)Fa[i]=i,siz[i]=1;
		for(int i = 1;i<=N&&y<ans;i++)if(bz[Ege[i].y]&&FA(Ege[i].x)!=FA(Ege[i].y))y+=Ege[i].val,merge(Ege[i].x,Ege[i].y);
		ans=min(ans,y);
		return;
	}
	bz[x]=0,sous(x+1,y),bz[x]=1,sous(x+1,y+c[x-n]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)cin>>EGE[i].x>>EGE[i].y>>EGE[i].val;
	sort(EGE+1,EGE+m+1,cmp);
	for(int i = 1;i<=n;i++)Fa[i]=i,siz[i]=bz[i]=1;
	for(int i = 1;i<=m;i++)if(FA(EGE[i].x)!=FA(EGE[i].y))merge(EGE[i].x,EGE[i].y),Ege[++N]=EGE[i];
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++)cin>>ipt,Ege[++N]={j,i+n,ipt}; 
	}
	sort(Ege+1,Ege+N+1,cmp);
	sous(n+1,0);
	cout<<ans;
} 
