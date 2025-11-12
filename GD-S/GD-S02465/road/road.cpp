#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[20];
int f[10020];
void init(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
}
int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}

bool merge(int x,int y){
//	cout<<"try merge "<<x<<","<<y<<"\n";
	x=fd(x);
	y=fd(y);
//	cout<<"f merge "<<x<<","<<y<<"\n";
	if(x==y)return 0;
	f[y]=x;
	return 1;
}
struct nd{
	int u,v,w;
}g[1000010],gg[10010],ggg[110010];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
void read(int &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
//		else f=1;
	}
	while(ch>='0'&&ch<='9'){
//		if(ch=='-')f=-1;
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}
int ct=0,cct;
int a[20][10010];
long long ans,res;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(g[i].u);read(g[i].v);read(g[i].w);
	}
	init();
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
//			if(a[i][j]==0){
//				cout<<i<<"->"<<j<<"\n";
//			}
		}
	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			if(a[i][j]==0){
//				cout<<i<<"->"<<j<<"\n";
//			}
//		}
//	}
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(merge(g[i].u,g[i].v)){
			gg[++ct]=g[i];
			ans+=g[i].w;
//			cout<<"upd "<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<"\n";
		}
//		if(i%n==1){
//			for(int i=1;i<=k;i++){
//				for(int j=1;j<=n;j++){
//					if(a[i][j]==0){
//						cout<<i<<"->"<<j<<"\n";
//					}
//				}
//			}
//		}
	}
//	cout<<ans<<"::::\n";
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			if(a[i][j]==0){
//				cout<<i<<"->"<<j<<"\n";
//			}
//		}
//	}
	for(int s=1;s<(1<<k);s++){
		for(int i=1;i<=ct;i++)ggg[i]=gg[i];
		cct=ct;
		res=0;
		for(int i=1;i<=k;i++){
			if(s&(1<<(i-1))){
				for(int j=1;j<=n;j++){
//					cout<<a[i][j]<<" ";
//					if(a[i][j]==0){
//						cout<<i<<"->"<<j<<"\n";
//					}
					ggg[++cct]={n+i,j,a[i][j]};
				}
				res+=c[i];
			}
//			cout<<"\n";
		}
//		cout<<res<<":::\n";
		sort(ggg+1,ggg+cct+1,cmp);
		init();
//		int ccct=0;
		for(int i=1;i<=cct;i++){
			if(merge(ggg[i].u,ggg[i].v)){
				res+=ggg[i].w;
//				cout<<"upd "<<ggg[i].u<<" "<<ggg[i].v<<" "<<ggg[i].w<<"\n";
//				ccct++;
			}
		}
		ans=min(ans,res);
//		cout<<ans<<":: "<<s<<" "<<ccct<<"\n";
	}
	cout<<ans;
	return 0;
}
/*
nklogn*2^k
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 0
100 1 3 2 4

1024n+1024*5n=6144n 
11n+10n*10+9n*45...+n
*/
