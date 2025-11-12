#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct egde{
	long long to,w;
};
struct node{
	int x,y,z;
}a[1000006];
bool cmp(node c,node b){
	return c.z<b.z;
}
int fa[1000006];
vector<egde>V[10005];
long long dis[10005];
int find(int x){
	if(fa[x] == x){
		return x;
	}
	else{
		return fa[x] = find(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k == 0){
		for(int i = 1;i<=10005;i++){
			fa[i] = i;
		}
		sort(a+1,a+1+m,cmp);
		for(int i = 1;i<=m;i++){
			cout<<a[i].x<<a[i].y<<a[i].z<<endl;
			if(a[i].y<a[i].x){
				swap(a[i].x,a[i].y);
			}
		}
		int ans = 0;
		for(int i = 1;i<=m;i++){
			int x = a[i].x,y = a[i].y;
			if(find(x)!=find(y)){
				fa[x] = fa[y];
				ans+=a[i].z;
			}
		}
		cout<<ans;
	}
	else{
		
	}
	return 0;
}
