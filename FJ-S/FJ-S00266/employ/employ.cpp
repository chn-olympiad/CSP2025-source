#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s[10005],d,c[10005][10005],sum;
struct jgt{
	long long u,v,w;
}a[1000005];
int l(jgt i,jgt j){
	return i.w<j.w;
}
void ss(int i,int o){
	for(int j=1;j<=m;j++){
		if(c[a[i].u][j]==1){
			c[o][j]=1;
			c[j][o]=1;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>d;
		for(int j=1;j<=n;j++){
			cin>>s[j];
		}
		for(int j=1;j<=m;j++){
			if(a[j].w>s[a[j].u]+s[a[j].v]+d)a[j].w=s[a[j].u]+s[a[j].v]+d;
		}
	}
	sort(a+1,a+m+1,l);
	for(int i=1;i<=m;i++){
		if(c[a[i].u][a[i].v]==0)sum+=a[i].w;
		c[a[i].u][a[i].v]=1;
		c[a[i].v][a[i].u]=1;
		ss(a[i].u,a[i].v);
		ss(a[i].v,a[i].u);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
