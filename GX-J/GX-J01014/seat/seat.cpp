#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,zz=0;
    cin>>n>>m;
    int c[n*m];
    int a[n*m];
    int b[n][m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(c[i]<c[j]){
                zz=c[i];
				c[i]=c[j];
				c[j]=zz;
                zz=0;
			}
		}
	}
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            b[j][i]==c[j];
            if(c[i]==a[i]){
                cout<<b[j][i];
                break;
            }
        }
    }
    return 0;
}
