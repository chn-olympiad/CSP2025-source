#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int N=1e6+10;
struct node{
	int to,next;
	ll len;
};
int n,m,k;
int h[N]={},tot=0;
void add(int x,int y,ll z){
	e[++tot]=(node){y,h[x],z}
	h[x]=tot;
}
int vis[N];
void ab(){
	int v=1,u=2;
	ll minn=e[1].len;
	for(int i=1;i<=m;i++){
		if(e[i].len<minn){
			minn=e[i].len;
			v=e[i].x;u=e[i].y;
		}
	}
	vis[i]=1;
	for(int i=h[v];i;i=e[i].next){
		int to=e[i].to;
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll sum=0;
	for(int i=1;i<=m;i++){
		int a,b;ll c;
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		add(a,b,c);
		sum+=c;
		//add(b,a,c);
	}
	cout<<sum;
	return 0;
}
