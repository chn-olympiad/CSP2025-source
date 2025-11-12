#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010][5];
int f[200010][5];
int n1=0,n2=0,n3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		f[0][1]=f[0][2]=f[0][3]=0;
		for(int i=1;i<=n;i++){
			int tmp=max(max(f[i-1][1],f[i-1][2]),f[i-1][3]);
			f[i][1]=tmp+a[i][1];
			f[i][2]=tmp+a[i][2];
			f[i][3]=tmp+a[i][3];
		}
		int maxn=0;
//		
//		cout<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++)cout<<f[i][j]<<' ';
//			cout<<'\n';
//		}
//		cout<<'\n'<<'\n';
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++)cout<<num[i][j]<<' ';
//			cout<<'\n';
//		}
//		cout<<'\n';
//		
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)maxn=max(maxn,f[i][j]);
		cout<<maxn<<'\n';
	}
	return 0;
}
