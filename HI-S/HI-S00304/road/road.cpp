#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long minl=0;
struct node{
	int u,v;
	long long w;
};
long long sum=0;
node a[1100005];
node b[1100005];
int f[10025];
int f2[10025];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
	//freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].v>>a[i].u>>a[i].w;
		if(a[i].v>a[i].u){
			swap(a[i].v,a[i].u);
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		if(f[a[i].v]!=f[a[i].u]){
			sum+=a[i].w;
			int fxa=f[a[i].u],fxb=f[a[i].v];
			for(int i=0;i<=n;i++){
				if(f[i]==fxa){
					f[i]=fxb;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
