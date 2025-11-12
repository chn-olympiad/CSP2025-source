#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[1000005],c[100005],a[15][10005],idx;
bool flag=1;
long long ans;
struct Edge{
	int from,to,dis;
}kkk[4000005];
inline bool cmp(Edge a,Edge b){return a.dis<b.dis;}
inline int Find(int x){if(s[x]==x) return x;return s[x]=Find(s[x]);}
inline void Merge(int x,int y){x=Find(x);y=Find(y);s[x]=y;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);idx=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&kkk[i].from,&kkk[i].to,&kkk[i].dis);
	}
	for(int i=1;i<=n;i++) s[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		int doubao=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) doubao=j;	
		}
		if(doubao!=0&&c[i]==0){
			for(int j=1;j<=n;j++){
				if(j!=doubao) kkk[++idx].from=doubao,kkk[idx].to=j,kkk[idx].dis=a[i][j];
			}
		}
	}
	sort(kkk+1,kkk+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		if(Find(kkk[i].from)!=Find(kkk[i].to)){
			Merge(kkk[i].from,kkk[i].to);
			ans+=kkk[i].dis;
		}
	}
	printf("%lld",ans);
}
