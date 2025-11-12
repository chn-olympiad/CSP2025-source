#include<bits/stdc++.h>
#define pii pair<int,int>
#define psbk push_back
#define fi first
#define se second

using namespace std;
const int N=35,INF=0x3f3f3f3f;
int n,a[N][3],f[N][N/2][N/2][3],t;
void sveA(){
	int b[N];
	for(int i=1;i<=n;i++) b[i]=a[i][0];
	sort(b+1,b+1+n);
	int an=0;
	for(int i=n/2+1;i<=n;i++) an+=b[i];
	cout<<an<<endl;
	return ;
}
void sveB(){
	int g[205][105][2];
	memset(g,-INF,sizeof(g));
	g[1][1][0]=a[1][0]; g[1][0][1]=a[1][1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			if(j) g[i][j][0]=max(g[i][j][0],max(g[i-1][j-1][0],g[i-1][j-1][1])+a[i][0]);
			g[i][j][1]=max(g[i][j][1],max(g[i-1][j][0],g[i-1][j][1])+a[i][1]);
		    //cout<<"B "<<i<<' '<<j<<" g: "<<g[i][j][0]<<' '<<g[i][j][1]<<endl;
		}
	}
	cout<<max(g[n][n/2][0],g[n][n/2][1])<<endl;
	return ;
}
int maf(int i,int j,int k){
	return max(f[i][j][k][0],max(f[i][j][k][1],f[i][j][k][2]));
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f0=1,f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]) f0=0;
			if(a[i][1]) f1=0;
			if(a[i][2]) f2=0;
		}
		if(f1&&f2){
			sveA();
			continue; 
		}
		if(f2){
			sveB();
			continue;
		}
		memset(f,-INF,sizeof(f));
		f[1][1][0][0]=a[1][0]; f[1][0][1][1]=a[1][1]; f[1][0][0][2]=a[1][2];
		for(int i=2;i<=n;i++){
			for(int x=0;x<=n/2;x++){
				for(int y=0;y<=n/2;y++){
					if(x) f[i][x][y][0]=maf(i-1,x-1,y)+a[i][0];
					if(y) f[i][x][y][1]=maf(i-1,x,y-1)+a[i][1];
					f[i][x][y][2]=maf(i-1,x,y)+a[i][2];
				}
			}
		}
		int an=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2) continue;
				an=max(an,maf(n,i,j));
			}
		}
		cout<<an<<endl;
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
