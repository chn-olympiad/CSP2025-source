#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=205;
int f[N][N][N],a[100005][4];//60pts
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof(f));
		bool cd=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0){
					cd=1;
				}
			}
		}
		if(cd==0){
			priority_queue<int> q;
			for(int i=1;i<=n;i++){
				q.push(a[i][1]);
			}
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<endl;
			continue;
		}
		f[1][0][0]=a[1][1];
		f[0][1][0]=a[1][2];
		f[0][0][1]=a[1][3];
		for(int i=2;i<=n;i++){
			for(int j=n;j>=0;j--){
				for(int k=n;k>=0;k--){
					for(int r=n;r>=0;r--){
						if(j+r+k!=i||j>n/2||k>n/2||r>n/2)		continue;
						if(j==0){
							if(k==0){
								f[j][k][r]=f[j][k][r-1]+a[i][3];
							}
							else if(r==0){
								f[j][k][r]=f[j][k-1][r]+a[i][2];
							}
							else
								f[j][k][r]=max({f[j][k-1][r]+a[i][2],f[j][k][r-1]+a[i][3]});
						}
						else if(k==0){
							if(j==0){
								f[j][k][r]=f[j][k][r-1]+a[i][3];
							}
							else if(r==0){
								f[j][k][r]=f[j-1][k][r]+a[i][1];
							}
							else	f[j][k][r]=max({f[j-1][k][r]+a[i][1],f[j][k][r-1]+a[i][3]});
						}
						else if(r==0){
							if(j==0){
								f[j][k][r]=f[j][k-1][r]+a[i][2];
							}
							else if(k==0){
								f[j][k][r]=f[j-1][k][r]+a[i][1];
							}
							else	f[j][k][r]=max({f[j-1][k][r]+a[i][1],f[j][k-1][r]+a[i][2]});
						}
						else 
							f[j][k][r]=max({f[j-1][k][r]+a[i][1],f[j][k-1][r]+a[i][2],f[j][k][r-1]+a[i][3]});
					}
				}
			}
		}
		int ans=0;
		for(int j=n;j>=0;j--){
				for(int k=n;k>=0;k--){
					for(int r=n;r>=0;r--){
						if(j+r+k!=n)		continue;
						if(j>n/2||k>n/2||r>n/2)	continue;
//						cout<<j<<" "<<k<<" "<<r<<" "<<f[j][k][r]<<endl;
						ans=max(ans,f[j][k][r]);
					}
				}
			}
		cout<<ans<<endl;
	}
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
