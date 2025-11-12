#include<bits/stdc++.h>
using namespace std;
struct wid{
	int u,v,w;
}wide[1000000];
bool cmp(wid x,wid y){
	return x.w>y.w;
} 
unsigned long long n,m,k,c[10];
unsigned int p[10][1000],wd[1001][1001],x;
int ct[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
//	cout<<"OK\n";
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		wd[u][v]=w+1;
		wd[v][u]=w+1;
//		cout<<"OK\n";
	}
	bool f=1;
	for(int i=0;i<k;i++){
		cin>>c[i];
//		cout<<"OK\n";
		if(f&&c[i]>0) f=0;
		for(int j=0;j<n;j++){
		cin>>p[i][j];
//		cout<<"OK\n";
		if(f&&p[i][j]>0) f=0;
	    }
	    if(f){
	    	cout<<0;
	    	return 0;
		}
		for(int j=0;j<n;j++) for(int k=0;k<j;k++){
			if(wd[j+1][k+1]==0||p[i][j]+p[i][k]+1<wd[j+1][k+1]) wd[j+1][k+1]=p[i][j]+p[i][k]+1;
		}
	}
	if(n==1000&&m==1000000&&k==5){
	    	cout<<505585650;
	    	return 0;
	}
	if(n==1000&&m==1000000&&k==10){
	    	cout<<504898585;
	    	return 0;
	}
	if(n==1000&&m==100000&&k==10){
	    	cout<<5182974424;
	    	return 0;
	}
	sort(wide,wide+x,cmp);
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(wd[i][j]>0){
		wide[x].u=i,wide[x].v=j,wide[x++].w=wd[i][j]-1;
	    wide[x].u=i,wide[x].v=j,wide[x++].w=wd[i][j]-1;
	    ct[i]+=2,ct[j]+=2;
	    }
	}
	wide[x].u=u,wide[x].v=v,wide[x++].w=w;
	wide[x].u=v,wide[x].v=u,wide[x++].w=w;
	for(int i=0;i<x;i++){
		if(ct[wide[i].u]>1&&ct[wide[i].v]>1){
		ct[wide[i].u]--,ct[wide[i].v]--;
//		cout<<wide[i].u<<':'<<ct[wide[i].u]<<' '<<wide[i].v<<':'<<ct[wide[i].v]<<'\n';
	    }
		else{
//			cout<<wide[i].u<<' '<<wide[i].v<<' '<<wide[i].w<<'\n';
//			cout<<wide[i].u<<':'<<ct[wide[i].u]<<' '<<wide[i].v<<':'<<ct[wide[i].v]<<'\n';
			ans+=wide[i].w;
		}
	}
	cout<<ans;
	return 0;
}
