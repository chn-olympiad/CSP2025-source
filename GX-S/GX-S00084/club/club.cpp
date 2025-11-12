#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N][4];
int maxx=-1,b[4],c[10][N],num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;++i){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));		
		cin>>n;
		for(int j=1;j<=3;++j){
			b[j]=n/2;
		}
		for(int j=1;j<=n;++j){
			for(int k=1;k<=3;++k){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=3;++j){
			for(int k=b[j];k>=0;--k){
				c[j][k]=max(c[j][k],c[j][k-1]+a[j][k]);
			}
		}
		for(int j=1;j<=n;++j){
			
		}
	}
	return 0;
}
