#include <bits/stdc++.h>
using namespace std;
int n,m,K,S;
struct BB{
	int x,y,id;
	long long val;
}bb[1000005];
bool cmp(BB A,BB B){
	return A.val<B.val;
}
int fa[20005];
int fin(int w){
	if(fa[w]==w)return w;
	return fa[w]=fin(fa[w]);
}
long long ans=LONG_LONG_MAX,js,hf[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	S=(1<<K)-1;
	for(int i=1;i<=m;i++){
		cin>>bb[i].x>>bb[i].y>>bb[i].val;
		bb[i].id=0;
	}
	sort(bb+1,bb+m+1,cmp);
	js=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(fin(bb[i].x)!=fin(bb[i].y)){
			fa[fa[bb[i].x]]=fa[bb[i].y];
			js+=bb[i].val;
		}
		else bb[i].val=INT_MAX;
	}
	ans=min(ans,js);
	sort(bb+1,bb+m+1,cmp);
	m=n-1;
	for(int i=1;i<=K;i++){
		cin>>hf[i];
		for(int j=1;j<=n;j++){
			m++,bb[m].x=j,bb[m].y=n+i,bb[m].id=i;
			cin>>bb[m].val;
		}
	}
	sort(bb+1,bb+m+1,cmp);
	for(int mms=1;mms<=S;mms++){
		js=0;
		for(int i=1;i<=K;i++){
			if(mms&(1<<(i-1)))js+=hf[i];
		}
		for(int i=1;i<=n+K;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			if(bb[i].id==0||(mms&(1<<(bb[i].id-1)))){
				if(fin(bb[i].x)!=fin(bb[i].y)){
					fa[fa[bb[i].x]]=fa[bb[i].y];
					js+=bb[i].val;
					if(ans<=js)break;
				}
			}
		}
		ans=min(ans,js);
	}
	cout<<ans;
	return 0;
}
