#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
	bool d;
};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    road r[m];
	bool c[n];
    int x=INT_MAX,y;
    for(int i=0;i<m;i++){
    	cin>>r[i].u>>r[i].v>>r[i].w;
    	r[i].d=1;
    	if(r[i].w<x){
    		x=r[i].w;
    		y=i;
		}
	}
	for(int i=0;i<n;i++){
		c[i]=0;
	}
	r[y].d=1;
	int ans=x;
	c[r[y].u]=1;
	c[r[y].v]=1;
	cout<<ans;
	
	return 0;
} 
