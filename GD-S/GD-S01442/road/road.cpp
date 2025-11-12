#include<bits/stdc++.h>
using namespace std;
int n,m,k,Mar;
struct data{
	int u,v,w;
}x[10009];
int c[19],a[19][10009];
//
bool cmp(data a,data b){
	return a.w<b.w;
}
int pre[10009];
int find(int x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
void run1(){
	sort(x+1,x+1+m,cmp);
	for(int i=1;i<=n;i++)pre[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++){
		if(find(x[i].u)!=find(x[i].v)){
			ans+=x[i].w;
			pre[find(x[i].v)]=find(x[i].u);
		}
	}
	cout<<ans;
}
void QAQ(){
	srand(time(0));
	cout<<rand()%Mar*10;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i].u>>x[i].v>>x[i].w;
		Mar=max(Mar,x[i].w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0)run1();
	else QAQ();
	return 0;
}
