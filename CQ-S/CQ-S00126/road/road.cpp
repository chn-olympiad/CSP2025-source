#include<bits/stdc++.h>
using namespace std;
int sum,n,m,k,a,f[100005];
struct no{
	int u,v,w;
}s[1000005];
int g(int x){
	if(f[x]==x)return f[x];
	f[x]=g(f[x]);
	return f[x];
}
bool cmp(no a,no b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
		if(s[i].u>s[i].v)swap(s[i].u,s[i].v);
		f[i]=i;
	}
		for(int j=1;j<=k;j++){
			cin>>a;
			for(int i=1;i<=n;i++){
				cin>>a;
				s[i+j].u=j;
				s[i+j].v=j;
				s[i+j].w=a;
			}
		}
		int k2=0;
		sort(s+1,s+m+k+1,cmp);
		for(int i=1;i<=m+k;i++){
			if(g(s[i].v)!=g(s[i].u)){
				k2++;
				sum+=s[i].w;
				f[g(s[i].v)]=g(s[i].u);
			}
			if(k2>=n-1)break;
		}
		cout<<sum<<endl;
	return 0;
}
