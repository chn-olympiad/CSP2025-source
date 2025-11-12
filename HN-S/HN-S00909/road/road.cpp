#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct aaa{
	int a,b;
};
vector <aaa> a[10050];
int b[10050]{};
int ans=999999999;
void aaa(int x,int f[],int s){
	if(s>ans){
		return;
	}
	if(f[0]==n){
		ans=min(ans,s);
		return;
	}
	for(auto y:a[x]){
		if(f[y.a]){
			continue;
		}
		f[y.a]=1;
		if(y.a>n){
			s+=b[y.a];
		}
		else{
			f[0]++;
		}
		aaa(y.a,f,s+y.b);
		f[y.a]=0;
		if(y.a<=n) f[0]--;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int w;
		scanf("%d",&w);
		b[n+i]=w;
		for(int j=1;j<=n;j++){
			int b;
			scanf("%d",&b);
			a[j].push_back({n+i,b});
			a[n+i].push_back({j,b});
		}
	}
	for(int i=1;i<=n;i++){
		int f[10050]{};
		f[i]=f[0]=1;
		aaa(i,f,0);
	}
//    int f[10050]{};
//    f[1]=f[0]=1;
//    aaa(1,f,0);
	printf("%d",ans);
	return 0;
}
