//Hello Gay!
//Hello Gay!
//Hello Gay!
//Hello Gay!
#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}a[1000005];
bool cmp(road &x,road &y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,b[1],c[100005];
	long long ans=0,num=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].v,&a[i].u,&a[i].w);	
	for(int i=1;i<=k;i++) scanf("%d",&b[1]);
	for(int j=1;j<=n;j++) c[j]=j;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(c[a[i].v]!=c[a[i].u]){c[a[i].v]=c[a[i].u];ans+=a[i].w;num++;}
		//cout<<num<<" ";
		if(num==n){break;}
	}
	cout<<ans;
	return 0;
}
//Hello Gay!
//Hello Gay!
//Hello Gay!
//Hello Gay!
