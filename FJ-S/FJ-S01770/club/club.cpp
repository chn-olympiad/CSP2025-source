#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[4];
long long f[3][1005][1005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		long long Max=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[j];
			int now=i&1,nxt=(i-1)&1;
			for(int j=0;j<=min(i,n>>1);j++){
				for(int k=0;k<=min(i-j,n>>1);k++){
					if(i-j-k<=(n>>1)){
						if(i-j-k)f[now][j][k]=max(f[now][j][k],f[nxt][j][k]+a[3]);
						if(j)f[now][j][k]=max(f[nxt][j-1][k]+a[1],f[now][j][k]);
						if(k)f[now][j][k]=max(f[nxt][j][k-1]+a[2],f[now][j][k]);
						Max=max(Max,f[now][j][k]);
						//cout<<f[i-1][j-1][k]+a[i][1]<<" "<<f[i-1][j][k-1]+a[i][2]<<" "<<f[i-1][j][k]+a[i][3]<<endl;
					}
				}
			}
		}
		cout<<Max<<"\n";
	}
	return 0;
} 
/*
2
10 9 8
4 0 0

*/
