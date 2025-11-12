#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],c[15],a[15][10000],ans=0;
int mw/*,ma[100005]*/,maa=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;j++){
		cin>>c[j]; 
		for(int i=0;i<n;i++){
			cin>>a[j][i];
		}
	}
	mw=w[0];
	for(int i=0;i<m;i++){
		if(w[i]>mw)mw=w[i];
	}
	ans=mw;
	maa=a[0][0];
	for(int j=0;j<k;j++){
		for(int i=0;i<n;i++){
			if(a[j][i]<maa)maa=a[j][i];
		}
		//ma[j]=maa;
		ans+=maa;
	}
	cout<<ans+1;
	return 0;
}
