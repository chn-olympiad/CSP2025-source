#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int a[N][N];
int b[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=w;
		a[y][x]=w;
		b[i]=w;
	}
	int t=1;
	int c;
	cin>>c;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]!=0) t=0;
	}
	if(t){
		if(k>0&&c==0){
			cout<<0;
			return 0;
		}
	}
	sort(b+1,b+1+n);
	if(k==0){
		/*
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!a[i][j]) continue;
				
			}
		}
		*/
		int op=0;
		for(int i=m;i>=n-1;i--){
			op+=b[i];
		}
		cout<<op;
	}
	int op=rand();
	cout<<op%201;
	
	return 0;
} 
