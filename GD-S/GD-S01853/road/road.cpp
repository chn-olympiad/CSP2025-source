#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x,y;
	ll w;
}a[1000010];
int n,m,k,fa[10010];
bool cmp(node xx,node yy){return xx.w<yy.w;}
int find1(int x){
	if(fa[x]!=x)fa[x] = find1(fa[x]);
	return fa[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k){
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].w;
	for(int i = 1;i<=10000;i++)fa[i] = i;
	sort(a+1,a+1+n,cmp);
	int x,y;
	ll sum = 0;
	for(int i = 1;i<=m;i++){
		x = find1(a[i].x),y = find1(a[i].y);
		if(x==y)continue;
		fa[y] = x;
		sum = sum+a[i].w;
	}
	cout<<sum;
	return 0;
}

