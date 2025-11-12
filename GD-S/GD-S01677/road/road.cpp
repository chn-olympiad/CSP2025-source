#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second 
int bin[10005];
int find(int kk){
	if(bin[kk]==kk)return kk;
	return bin[kk]=find(bin[kk]);
}
vector<pair<int,pair<int,int> >>ve;
bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
	return a.x>b.x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)bin[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ve.push_back({w,{u,v}});
	}
	if(k==0){
		long long ans=0;
		sort(ve.begin(),ve.end(),cmp);
		for(int i=ve.size()-1;i>=0;i--){
			if(find(ve[i].y.x)==find(ve[i].y.y))continue;
			bin[find(ve[i].y.x)]=ve[i].y.y;
			ans+=ve[i].x;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
