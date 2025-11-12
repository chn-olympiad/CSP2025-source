//GZ-S00359 罗义凯 贵阳雅礼高级中学（贵阳市第九中学）
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000005],b[5000][5000];
int em(int x){
	if(a[x]!=x){
		return a[x]=em(a[x]);
	}
	else{
		return x;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	for(int i=1;i<=m;i++){
		int e,r,w;
		cin>>e>>r>>w;
		a[e]=r;
		a[r]=e;
		b[r][e]=w;
		b[e][r]=w;
	}
	a[1]=1;
	int su=0;
	for(int i=1;i<=m;i++){
		for(int j=m;j>i;j--){
			if(em(i)!=em(j)) su+=b[i][j];
		}
	}
	cout<<su<<endl;
	return 0;
} 
