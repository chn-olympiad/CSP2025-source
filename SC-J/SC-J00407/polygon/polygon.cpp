#include<bits/stdc++.h>
using namespace std;
int a[3][5001],b[3][5001],c[3][5001];
int main(){
	int n,k[5001]={0},ans=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	sort(k,k+n);
	for(int i=1;i<=2;i++){
		for(int j=0;j<k[i];j++){
			a[i][j]=a[i-1][j]+1;
		}
	}
	for(int i=0;i<=k[1];i++){
		for(int j=0;j<k[2]+a[1][i];j++){
			b[2][j]++;
		}
	}
	for(int i=3;i<=n;i++){
		
		int u1=0,u2=0,u3=0;
		for(int j=0;j<5001;j++){
			a[1][j]=a[2][j];
			b[1][j]=b[2][j];
			c[1][j]=c[2][j];
		}
		if(k[i]>u1){
			u1=k[i];
		}
		for(int j=0;j<k[i];j++){
			a[2][j]=a[1][j]+1;
		}
		for(int h=0;h<=u1;h++){
			int p=a[1][h];
			for(int j=0;j<h+k[i];j++){
				b[2][j]=(b[1][j]+p)%998244353;
				u2=max(u2,h+k[i]);
			}
		}
		for(int h=0;h<=u2;h++){
			int p=b[1][h];
			for(int j=0;j<h+k[i];j++){
				c[2][j]=(c[1][j]+p)%998244353;
				u3=max(u3,h+k[i]);
			}
			for(int j=2*k[i];j<=u3;j++){
				ans=(ans+c[2][j])%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
} 