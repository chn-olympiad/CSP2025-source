#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int w[N][5],f[N][5][N],k[5],a[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(w,0,sizeof w);
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>w[i][j];
		for(int i=n-1;i>=0;i--){
			for(int j=1;j<=3;j++){
				for(k[j]=n/2;k[j]>=0;k[j]--){
					f[i][j][k[j]]=max(max(f[i+1][1][k[1]-1]+w[i][j],f[i+1][2][k[2]-1]+w[i][j]),f[i+1][3][k[3]-1]+w[i][j]);
				}
			}
		}
		for(int i=1;i<=n/2;i++)
			a[1]=max(a[1],f[0][1][i]);
		for(int i=1;i<=n/2;i++)
			a[2]=max(a[2],f[0][2][i]);
		for(int i=1;i<=n/2;i++)
			a[3]=max(a[3],f[0][3][i]);
		cout<<max(max(a[1],a[2]),a[3])<<endl;
	}
	return 0;
}
