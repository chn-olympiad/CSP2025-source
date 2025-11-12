#include<bits/stdc++.h>
using namespace std;
int n,a[5001][5001],b[5001],ans,c[5001],d[5001][5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		c[i]=c[i-1]+b[i];
	}
	sort(b+1,b+1+n);
	for(int i=n;i>=2;i--){
		for(int j=n-1;j>=1;j--){
			d[i-j][c[i]-c[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[n]-b[1];j++){
			d[i][j]+=d[i][j-1];
		}
	}
	for(int i=2;i<=n;i++){
		a[2][i]=i-1;
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[i][j]=a[i-1][j-1];
			a[i][j]-=d[i-1][b[j]];
			a[i][j]%=998244353;
			ans+=a[i][j];
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}

