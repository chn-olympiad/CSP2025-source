#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10,MAXM=1e4+10;
int n,m,k,fa[MAXM],ans=0;
struct node{
	int u,v,w;
}a[MAXN];
int find(int i){
	return (fa[i]==i?i:fa[i]=find(fa[i]));
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void ku(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1,cmp);
	int cnt=n;
	for(int i=1;i<=m;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y)continue;
		ans+=a[i].w;
		cnt--;
		if(cnt==1)break;
	}
	return;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	ku(); 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
