#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ns[1010][1010]={},ans=0;
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		ns[x][y]=z;
		ns[y][x]=z;
	}
	for(int i=0;i<k;i++){
		int x,c,y;
		vector<int>v;
		cin>>x;
		for(int j=0;j<n;j++){
			cin>>c;
			for(int k=0;k<v.size();k++) if(j!=k){
				y=x+c+v[k];
				if(ns[j+1][k+1]==0){
					ns[j+1][k+1]=y;
				}
				else{
					ns[j+1][k+1]=min(ns[j+1][k+1],y);
				}
				ns[k+1][j+1]=ns[j+1][k+1];
			}
			v.push_back(c);
		}
	}
	int minns[101]={},minn=INT_MAX,b=1;
	bool bs[101]={};
	for(int j=2;j<=n;j++){
		minns[j]=ns[1][j];
		if(minn<minns[j]){
			minn=minns[j];
			b=j;
		}
	}
	ans+=minns[b];
	bs[b]=1;
	for(int i=2;i<=n;i++){
		minn=INT_MAX;
		for(int j=1;j<=n;j++) if(i!=j&&bs[j]==0){
			minns[j]=min(minns[j],ns[b][j]);
			if(minns[j]<minn){
				minn=minns[j];
				b=j;
			}
		}
		bs[b]=1;
		ans+=minns[b];
	}
	cout<<ans;
	return 0;
}