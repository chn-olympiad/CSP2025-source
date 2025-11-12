#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1;
	int s[10][10],a[10][10];
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
            cin>>a[i][j];
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
            if(a[1][1]<a[i][j]){
                x++;
            }
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
            if(x==1){
                cout<<1<<" "<<1;
                return 0;
            }if(i%2!=0){
                if((i-1)*n+j==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }if(i%2==0){
                if((i-1)*n*2+n-x+1==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
		}
	}
}
