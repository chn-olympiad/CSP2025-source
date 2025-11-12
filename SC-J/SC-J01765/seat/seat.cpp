#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int ax[105];
int cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ax[i];
	}
	int a1=ax[1];
	sort(ax+1,ax+n*m+1,cmp);
	int ix=0;
	int k=0;
	
	for(int i=1;i<=m;i++){
		if(k==0){
			for(int j=1;j<=n;j++){
				ix++;
				a[j][i]=ax[ix];
				if(ax[ix]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			k=1;
		}
		else if(k==1){
			for(int j=n;j>=1;j--){
				ix++;
				a[j][i]=ax[ix];
				if(ax[ix]==a1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
			k=0;
		}
	}
	return 0;
} 