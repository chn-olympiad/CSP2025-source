#include<bits/stdc++.h>
using namespace std;
int a[100001][100001];
int cnt=0;	
int n,k;
struct line{
	int v;
	int w;
}h[5000005];
int v[500005];
int w[500005];
bool cmp(line a,line b){
	if(a.v==b.v){
		return a.w<b.w;
	}
	return a.v<b.v;
}
int dfs(int x,int it){
	if(x>n){
		return 1;
	}
	int res=0;
	for(;h[it].v<=x;it++){
		if(h[it].v==x) res=max(res,dfs(h[it].w,it+1));
	}
	return max(res,dfs(x+1,it+1));
}
int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
//		if(                    ){
//			b[++cnt].v=i-len+1;
//			h[cnt].w=i;
//		}
	}
	for(int len=2;len<=n;len++){
		for(int i=len;i<=n;i++){
			if(a[i][len]==a[i-1][len-1]^a[i][1]){
				a[cnt].v=i-len+1;
				h[cnt].w=i;
			}
		}
	}
	sort(h+1,h+1+cnt,cmp);
	cout<<dfs(1,1);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
