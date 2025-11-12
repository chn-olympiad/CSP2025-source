#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long n,m,k,ans=0;
int a[N][6];
int c[N][10];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			ans+=a[i][3];
		}		
	}
	for(int j=0;j<=k;j++)for(int i=0;i<=m+1;i++)
			cin>>c[j][i];
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
	return 0;
}

