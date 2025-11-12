#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5; 
int w[N];
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)w[i]=1e9;
	for(int i=0;i<m;i++){
		int u,v,ww;
		cin>>u>>v>>ww;
		w[u]=min(ww,w[u]);
		w[v]=min(ww,w[v]);
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			for(int l=1;l<j;l++){
				int tmp=c+a[j]+a[l];
				w[j]=min(tmp,w[j]);
				w[l]=min(tmp,w[l]);
			}
		}
	}
	int sum=0,minn=1e9;
	for(int i=1;i<=n;i++){
		sum+=w[i];
		minn=min(w[i],minn);
	}
	cout<<sum-minn;
}
