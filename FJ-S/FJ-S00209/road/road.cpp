#include<bits/stdc++.h>

using namespace std;

int n,m,k;
int book[10001];

struct node{
	int u,v,w;
}q[10001];

bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cin>>q[1].u>>q[1].v>>q[1].w;
	book[q[1].u]=q[1].v=1;
	for(int i=2;i<=n;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
		if(book[q[i].u]!=0) book[q[i].v]=book[q[i].u];
		else if(book[q[i].v]!=0) book[q[i].u]=book[q[i].v];
		else book[q[i].u]=book[q[i].v]=i;
	}
	sort(q+1,q+1+n,cmp);
	int sum=0;
	for(int i=1;i<=2;i++){
		sum+=q[i].w;
	}
	cout<<sum<<endl;
	return 0;
}
