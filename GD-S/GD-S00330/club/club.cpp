#include<bits/stdc++.h>
using namespace std;
int T,n,a[102][102][102],d[100005][4],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
			cin>>d[i][1]>>d[i][2]>>d[i][3];
		if(n<=202){
			for(int l=1;l<=n;l++){
				for(int i=0;i<=min(l,n/2);i++){
					for(int j=0;j<=min(l-i,n/2);j++){
						int k=l-i-j;
						if(k>n/2)continue;
						if(i>0)a[i][j][k]=max(a[i][j][k],a[i-1][j][k]+d[l][1]);
						if(j>0)a[i][j][k]=max(a[i][j][k],a[i][j-1][k]+d[l][2]);
						if(k>0)a[i][j][k]=max(a[i][j][k],a[i][j][k-1]+d[l][3]);
						//cout<<i<<" "<<j<<" "<<k<<" "<<a[i][j][k]<<endl;
					}
				}
			}
			/*for(int i=0;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(i+j+k==n)cout<<a[i][j][k]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
			}*/
			int ans=-1;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int k=n-i-j;
					if(k>n/2)continue;
					ans=max(ans,a[i][j][k]);
				}
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)c[i]=d[i][1];
			sort(c+1,c+n+1);
			for(int i=n/2+1;i<=n;i++)ans+=c[i];
			cout<<ans<<endl;
		}
	}
	return 0;
} 
/*
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
