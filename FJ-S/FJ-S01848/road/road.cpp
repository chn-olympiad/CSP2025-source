#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[10100][10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k+1;j++){
			a[i][j]=LONG_LONG_MAX;
		}
	}
//	for(int i=1;i<=m+k;i++){
//		a[i][i]=0;
//	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int q;
	int qq[10100];
	for(int i=m+1;i<=k+m;i++){
		cin>>qq[i];
		a[i][i]=qq[i];
		for(int j=1;j<=n;j++){
			cin>>q;
			a[i][j]=q+qq[i];
			a[j][i]=q+qq[i];
		}
		a[0][i]=1;
		a[i][0]=1;
	}
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k;j++){
			a[i][m+k+1]=min(a[i][m+k+1],a[i][j]);
		}
	}
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k;j++){
			//for(int l=1;l<=m+k;l++){
			a[i][j]=min(a[i][j],a[i][m+k+1]+a[j][m+k+1]);
			//}
			a[i][i]=LONG_LONG_MAX;
		}
	}
	long long s=0;
	for(int i=1;i<=m+k;i++){
		for(int j=1;j<=m+k;j++){
			if(a[i][j]==a[i][m+k+1]){
				s+=a[i][j];
				if((i>m&&(a[i][0]==0||a[0][i]==0))||(j>m&&(a[j][0]==0||a[0][j]==0))){
					s-=qq[i];
					s-=qq[j];
					//cout<<1<<endl;
				}
				a[i][0]=0;
				a[0][j]=0;
				a[j][0]=0;
				a[0][i]=0;
				//cout<<i<<" "<<j<<" "<<s<<endl;
			}
		}
	}
	
//	for(int i=1;i<=m+k+1;i++){
//		for(int j=1;j<=m+k+1;j++){
//			cout<<a[i][j]<<" ";
//		}cout<<endl;
//	}
	cout<<s;
	return 0;
}
//   1 2 3 4 5 6
//1        6 1 1
//2      7 5 8 3
//3    7   4 2 2
//4  6 5 4   4 4
//5  1 8 2 4 1
//6  1 3 2 4   100

//   1 2 3 4 5 6
//1  0 . . 6 -2 101
//2  . 0 7 -5 9 103
//3  . 7 0 -4 -3 102
//4  6 -5 -4 0 5 104
//5  -2 9 -3 5 0 .
//6  101 103 102 104 . 0

//  1 2 3 4 5 6 
//1 0 4 3 5 2 1  
//2 4 0 5 5 4 3  
//3 3 5 0 4 2 2  
//4 5 5 4 0 4 4  
//5 1 4 2 4 0 2  
//6 1 3 2 4 2 0 

//  1 2 3 4 5 6 
//1 0 4 3 5 2 1  
//2 4 0 5 5 4 3  
//3 3 5 0 4 2 2  
//4 5 5 4 0 4 4  
//5 1 4 2 4 0 2  
//6 1 3 2 4 2 0 


