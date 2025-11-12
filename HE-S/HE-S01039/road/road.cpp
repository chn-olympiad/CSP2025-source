#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k;
struct PII{
	int a,b,w;
}e[N];
int cnt=0;
int fa[N];
bool cmp(PII x,PII y){
	return x.w<y.w;
} 
int find(int x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	return fa[x]; 
}
int ans; 
void klsk(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].a;
		int y=e[i].b;
		int w=e[i].w;
		x=find(x),y=find(y);
		if(x!=y){
			fa[x]=y;
			ans+=w;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	
	for(int i=1;i<=m;i++){
		cin >>e[i].a >>e[i].b >>e[i].w;
	}
	

		klsk();
		cout <<ans;
		return 0;


	
	return 0;
} 
