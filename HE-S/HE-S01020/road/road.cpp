#include<bits/stdc++.h>
using namespace std;
int a,b;
int f[100005][100005];
int w,v,c;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	memset(f,0,sizeof());
	for(int i=1;i<=n;i++){
		
		cin>>w>>v>>c;
		f[w][v]=q;
		f[v][w]=q;
	}
	for(int i=0;i<k;i++){
		cin>>a;
		for(int j=0;j<n;j++){
			cin>>b;
			f[n+i][j]=a+b;
			f[j][n+i]=a+b;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i][j];
		cout<<ans;
	}
	
	
	return 0;
}
