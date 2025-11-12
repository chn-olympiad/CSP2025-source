#include<bits/stdc++.h>
using namespace std;
int id[10005],n,m,k,s=0;
long long ans;
int find(int a){
	if(id[a]==a) return id[a];
	return id[a]=find(id[a]);
}
void merge(int a,int b,long long v){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		id[x]=y;
		find(x);
		s++;
		ans+=v;
	}
}
struct date{
	int a,b;
	long long v;
}a[1000005];
bool cmp(date a,date b){
	return a.v<b.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) id[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		merge(a[i].a,a[i].b,a[i].v);
		if(s==n-1){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
