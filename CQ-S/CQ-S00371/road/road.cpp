#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node1{
	int x,y;
};
struct node{
	int x,y,z;
}a[100000005];
vector<node> v[10005];
int fath[10005];
int get_father(int x){
	if(fath[x]==x) return x;
	else return fath[x]=get_father(fath[x]);
}
bool cmp(node t1,node t2){
	return t1.z<t2.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		a[i].x=x;
		a[i].y=y;
		a[i].z=z;
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=n;i++) fath[i]=i;
		int fx,fy,sum=0;
		ll sum1=0;
		for(int i=1;i<=m;i++){
			fx=get_father(a[i].x),fy=get_father(a[i].y);
			if(fx!=fy){
				fath[fx]=fy;
				sum++;
				sum1+=a[i].z;
			}
			if(sum==n) break;
		}
		cout<<sum1;
		return 0;
	}
	return 0;
}
