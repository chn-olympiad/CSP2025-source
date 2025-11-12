#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;int f[maxn];int tracklost=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>f[i];
    }
    int ghosto=f[1];
    for(int i=1;i<=m*n;i++){
        if(ghosto<f[i]){
            tracklost+=1;
        }
    }
    int dx,dy;
    if(tracklost%n==0){
		dx=tracklost/n;
		dy=(dx%2)*(n-1)+1;
    }
    else{
		dx=tracklost/n+1;
		dy=-(dx%2)*(n-1)+n-(tracklost%n-1)*((n+1)%2);
    }
    cout<<dx<<" "<<dy<<endl;
    return 0;
}
