#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,sum=0;
    cin>>n>>m;
    int a[n*m+9][n*m+9];
    int b[n*m+9];
    for(int j=1;j<=n*m;j++){
            cin>>b[j];
    }
    int xx=b[1];
    sort(b+1,b+1+(n*m),cmd);

    int aa=1,ci=1;
    xixihaha:
    if(ci%2==0){
    	for(int i=n;i>0;i--){
			a[ci][i]=b[aa];
			aa++;
		}
	}else{
		
		for(int i=1;i<=n;i++){
    		a[ci][i]=b[aa];
    		aa++;
		}
	}
	ci++;
	if(ci<=m){
		goto xixihaha;
	}
    int bb=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
                if(a[i][j]==xx){
                    cout<<i<<' '<<j<<'\n';
                    return 0;
                }
        }
    }
    return 0;
}
