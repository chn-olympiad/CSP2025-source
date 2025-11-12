#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int a[5008][5008];
int cnt=0;
struct line{
	int v;
	int w;
}h[500008];
bool cmp(line a,line b){
	if(a.v==b.v){
		return a.w<b.w;
	}
	return a.v<b.v;
}
int n,k;
int dfs(int x,int it){
	if(x>n){
		return 0;
	}
	int res=0;
	for(;h[it].v<=x;it++){
		if(h[it].v==x)res=max(res,dfs(h[it].w+1,it+1)+1);
	}
	return max(res,dfs(x+1,it+1));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		if(a[i][1]==k){
			h[++cnt].v=i;
			h[cnt].w=i;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=len;i<=n;i++){
			a[i][len]=a[i-1][len-1]^a[i][1];
			if(a[i][len]==k){
				h[++cnt].v=i-len+1;
				h[cnt].w=i;
			}
		}
	}
	sort(h+1,h+1+cnt,cmp);
	cout<<dfs(1,1);
	return 0;
}