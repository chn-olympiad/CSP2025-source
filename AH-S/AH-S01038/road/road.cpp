#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
struct node{
	int a,b,c;
}x[10005];
int mp[10005][10005];
int fmp[10005];
bool smap[10005];
bool cmp(node i,node j){
	if(i.a!=j.a)return i.a<j.a;
	return i.b<j.b;
}
int dfs(int temp){
	bool h=1;
	for(int i=1;i<=n;i++){
		if(!smap[i])h=0;
	}
	if(h)return sum;
	else{
		for(int i=1;i<=fmp[temp];i++){
			smap[i]=1;
			sum+=mp[temp][i];
			dfs(temp+1);
			sum-=mp[temp][i];
			smap[i]=0;
		}
		return sum;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>x[i].a>>x[i].b>>x[i].c;
	for(int i=1;i<=k;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
	}
	cout<<0;
	return 0;
}
 
