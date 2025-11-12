#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n;
int m;
int k;
long long a[N][N];
long long s[N*100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j]=-1;
		}
	}
	int x,y;
	long long z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(a[x][y]<0){
			a[x][y]=z;
			a[y][x]=z;
		}else{
			if(z<a[x][y]){
				a[x][y]=z;
				a[y][x]=z;
			}
			
		}
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]>=0){
				s[++t]=a[i][j];
				//cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
			}
		}
	}
	sort(s+1,s+t);
	long long c=0;
	for(int i=1;i<n;i++){
		c+=s[i];
		
	}
	cout<<c;
	
}