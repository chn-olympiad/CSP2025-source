#include<bits/stdc++.h>
using namespace std;
int f[100010];
struct P{
	int u,v,w;
}a[100010];
int find(int x){
	if(f[x]==x){
		return f[x];
	}
	return f[x]=find(f[x]);
}
bool cmp(P a,P b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
    cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=m;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			int k=find(a[i].u),l=find(a[i].v);
			if(k!=l){
				f[k]=l;
				sum+=a[i].w;
			}
		}
		cout<<sum;	
	}
	else{
		cout<<0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
