#include<bits/stdc++.h>
using namespace std;
struct ss{
	int u,v,w;
};
ss s[1000005];
bool cmp(ss a,ss b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=n-k+1;i++){
		ans+=s[i].w;
	}
	cout<<ans;
	return 0;
}