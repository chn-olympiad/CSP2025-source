#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
typedef long long ll;
ll m,n,ans=-1,k,pd;
ll a[N][N];
ll build[11][N];
inline ll read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int x,y,w;
		x=read();y=read();w=read();
		a[x][y]=a[y][x]=w;
	}
	for(int i=1;i<=k;i++){
		build[i][0]=read();
		if(build[i][0]!=0) pd=1;
		for(int j=1;j<=n;j++){
			build[i][j]=read();
		}
	}
	if(pd==0)cout<<0<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0 


*/
