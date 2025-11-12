#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
const int M=1e3+10;
const int inf=0x3f3f3f3f;
struct node{
	int x,y,w;
}a[N];
bool cmp(node p,node q){
	return p.w<q.w;
}
int per[N];
int n,m,k;
int dis[M][M];
ll cost;
int find(int k){
	if(per[k]==k) return per[k];
	else return per[k]=find(per[k]);
}
void merge(int x,int y){
	int ax=find(x),ay=find(y);
	if(ax!=ay) per[ay]=ax;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){//MST
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);//xiao-->da
		for(int i=1;i<=n;i++) per[i]=i;
		int cnt=0; cost=0;
		for(int i=1;i<=m;i++){
			int ux=a[i].x,uy=a[i].y;
			if(per[ux]!=per[uy]){//no in tree
				cost+=a[i].w;
				merge(ux,uy);
				cnt++;
			}
			if(cnt==n-1){
				cout<<cost;
				return 0;
			}
		}
	}
	return 0;
}
