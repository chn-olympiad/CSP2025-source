#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline int in(){
	int k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&& c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
int a[10005][10005],co[10005][10005];
int vis[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x7f7f7f,sizeof a);
	int n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++){
		int u=in(),v=in(),w=in();
		a[u][v]=a[v][u]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[k][j]!=0x7f7f7f&&a[i][k]!=0x7f7f7f){
					if(a[i][j]>a[k][j]+a[i][k]){
						a[i][j]=a[j][i]=a[k][j]+a[i][k];
						
					}
				}
			}
		}
	}
	int p=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]!=0x7f7f7f){
				 p+=a[i][j];
				 vis[i]++;vis[j]++;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int c=in();
		for(int j=1;j<=n;j++){
			co[i][j]=in();
//			if(co[i][j]==0&&c==0) vis[j]=true;
//			else if(c+co[i][j]<=)
		}
	}
	cout << p;
	return 0;
} 
