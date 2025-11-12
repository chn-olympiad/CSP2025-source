#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,w[100005],sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>w[i];
		
	}sort(w+1,w+1+n);
	for(int i=1;i<=m-2;i++){
		sum+=w[i];
	}
	int minnn=1000000001,minn=1000000001,minc=1000000001;
	for(int i=1;i<=k;i++){
		int c;
		int a[100005];
		cin>>c;
		minc=min(c,minc);
		for(int j=1;j<=n;j++){		
			cin>>a[j];
			minn=min(minn,a[j]);
		}for(int j=1;j<=n;j++){		
			if(a[j]==minn)continue;
			minnn=min(minnn,a[j]);
		}
		
		
	}cout<<sum+minn+minc+minnn;
	
	return 0;
}
