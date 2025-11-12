#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int t=0;
long long ans=0;
struct jgt{
	long long to1,to2,v;
}a[15000005];
int f[11000];
int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}
bool an(int x,int y){
	int xf=find(x),yf=find(y);
	if(xf==yf) return 0;
	f[xf]=yf;
	return 1;
}
bool cmp(jgt x,jgt y){
	return x.v<y.v;
}
void klskr(){
	int d=0;
	for(int i=1;i<=t;i++){
		jgt now=a[i];
	
		if(an(now.to1,now.to2)){
			 ans+=now.v,d++;
			 
		}	
		if(d==n-1) break;
	}
	return;
}
int vvv[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[++t].to1=x;
		a[t].to2=y;
		a[t].v=z;
	}
	for(int i=1;i<=k;i++){
		int vv;
		cin>>vv;
		for(int j=1;j<=n;j++) {
			cin>>vvv[j];
		}
		for(int j=1;j<n;j++){
			for(int l=j+1;l<=n;l++){
				a[++t].to1=j;
				a[t].to2=l;
				a[t].v=vvv[j]+vvv[l]+vv;
				if(a[t].v<0) a[t].v=-a[t].v;
			}
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+t,cmp);
	klskr();
	cout<<ans;
	return 0;
}
