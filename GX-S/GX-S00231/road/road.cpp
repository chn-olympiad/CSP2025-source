#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,qwe=0;
    cin>>n>>m>>k;
    int fei[m+k*(n*n-n)/2][3],nf[k][1+n];
    for (int i=0;i<m;i++){
		cin>>fei[i][0]>>fei[i][1]>>fei[i][2];
		qwe+=fei[i][2];
	}
	for (int l=0;l<k;l++){
		cin>>nf[l][0];
		for (int i=1;i<=k;i++){
			cin>>nf[l][i];
		}
		for (int i=0;i<n-1;i++){
		    for (int j=i+1;j<=n;j++){
		        fei[m+l*4+i*n+j-1][0]=i+1;
		        fei[m+l*4+i*n+j-1][1]=i+j+1;
		        fei[m+l*4+i*n+j-1][2]=nf[l][i+1]+nf[l][i+j+1]+nf[l][0];
	        }
		}
	}
	cout<<qwe;
	
}
