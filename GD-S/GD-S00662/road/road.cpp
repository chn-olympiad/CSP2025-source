#include<bits/stdc++.h>
using namespace std;
struct sd{
	int x,y,z;
};
int n,m,k;
vector<sd> v;
int fa[114514];
int c[114514];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}void merge(int x,int y){
	x=get(x);
	y=get(y);
	fa[x]=y;
}bool cmp(sd x,sd y){
	return x.z<y.z;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v.push_back({x,y,z});
	}for(int i=1;i<=k;i++){
		cin>>c[0];
		int l=0;
		for(int j=1;j<=n;j++){
			cin>>c[j];
			if(c[j]==0){
				l=j;
			}
		}for(int j=1;j<=n;j++){
			v.push_back({l,j,c[j]});
		} 
	}init();
	sort(v.begin(),v.end(),cmp);
	long long sum=0,cnti=1;
	for(sd i:v){
		if(get(i.x)!=get(i.y)){
			merge(i.x,i.y);
			sum+=i.z;
			cnti++;
			if(cnti==n)break;
		}
	}cout<<sum;
	return 0;
} 
