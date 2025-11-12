#include<bits\stdc++.h>
using namespace std;
int fa[10005];
struct node{
	int from,to;
	int len;
};
bool cmp(node a,node b){
	return a.len<b.len;
}
node quas[1000005];
int findx(int i){
	if(fa[i]!=i) fa[i]=findx(fa[i]);
	return fa[i];
}
void uni(int a,int b){
	fa[a]=findx(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		cin>>quas[i].from>>quas[i].to>>quas[i].len;
	}
	sort(quas,quas+m,cmp);
	int tent;
	for(int i=0;i<k;i++){
		cin>>tent; 
		for(int j=1;j<=n;j++){
			cin>>tent;
		}
	}
	tent=0;
	int ans=0;
	for(int i=0;tent<n-1;i++){
		if(findx(quas[i].from)!=findx(quas[i].to)){
			tent++;
			ans+=quas[i].len;
			uni(quas[i].from,quas[i].to);
		} 
	}
	cout<<ans;
	return 0;
} 
