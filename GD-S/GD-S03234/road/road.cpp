#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct data{
	int u,v,w;
}a[1000010];
int ans=0,ans2=0;
bool cmp(data x,data y){
	return x.w<y.w;
}
bool f[1000010],num=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		if(num>=n)break;
		if(!f[a[i].u]){
			f[a[i].u]=true;
			num++;
		}if(!f[a[i].v]){
			f[a[i].v]=true;
			num++;
		}
		if(!(f[a[i].u]&&f[a[i].v]))ans2+=a[i].w;
	}
	cout<<ans2;
	return 0;
}
