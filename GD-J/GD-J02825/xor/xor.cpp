#include <bits/stdc++.h>
using namespace std;
#define For(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
const int M=500101;
const int inf=1e9+7;
int n,m,a[M],s[M],cnt;
int ans,lst;
struct edge{int l,r;}e[M];
vector <int> f[M];
bool cmp(edge x,edge y){return x.r<y.r;}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) s[i]=s[i-1]^a[i];
	f[0].push_back(0);
	For(i,1,n){
		f[s[i]].push_back(i);
		if(!f[s[i]^m].size()) continue;
		e[++cnt]={f[s[i]^m][f[s[i]^m].size()-1]+1,i};
	}
	sort(e+1,e+1+cnt,cmp);
	For(i,1,cnt){
		if(e[i].l>lst){
			ans++;
			lst=e[i].r;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
4 2
2 1 0 3
*/
