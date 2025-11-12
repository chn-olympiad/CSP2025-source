#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,m,f[10000],cnt=0,ans;
int u=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
		//cout<<f[i]<<" ";
	}
	ans=f[1];
	sort(f+1,f+1+(m*n),cmp);
	for(int i=1;i<=m;i++){
		if(u==0) for(int j=1;j<=n;j++){
			cnt++;
			a[i][j]=f[cnt];
			if(a[i][j]==ans) cout<<i<<" "<<j;
		}
		else if(u==1) for(int j=n;j>=1;j--){
			cnt++;
			a[i][j]=f[cnt];
			if(a[i][j]==ans) cout<<i<<" "<<j; 
		}
		u=!u;
		//cout<<u;
	}
	return 0;
} 
