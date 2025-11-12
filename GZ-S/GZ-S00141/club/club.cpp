//GZ-S00141 尹晟慧 六盘水市第四实验中学
#include<bits/stdc++.h>
using namespace std;
const int MAXN=205;
int t,n,a[MAXN][MAXN],f[MAXN][MAXN],b[MAXN][MAXN];
bool s(int x){
	if(x>=n/2+1) return false;
	else return true;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;i<=3;j++)
				cin>>a[i][j];
		a[1][1]=f[1][1];
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				if(f[i-1][j-1]>=f[i-1][j]){
					ans=max(f[i-1][j-1],f[i-1][j])+a[i][n];
				}
			}
		}
	}
	cout<<ans<<endl; 
	return 0;
}
