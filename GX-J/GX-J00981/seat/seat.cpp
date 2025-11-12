#include<bits/stdc++.h>

using namespace std;

int z(int d,int e){
    return d>e;
}

int c[10005]{};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1;
    cin>>n>>m>>a1;
    c[0]=a1;
    for(int i=1;i<n*m;i++){
        scanf("%d",&c[i]);
    }
    sort(c,c+m*n,z);
    int x=0,i=1,j=1;
    bool y=0;
    while(i<=n&&j<=m){
        if(c[x]==a1){
            cout<<i<<" "<<j;
            return 0;
        }
        if(y==0){
            j++;
        }
        if(y==1){
            j--;
        }
        if(j==m||j==1){
            if(c[x+1]==a1){
            cout<<i<<" "<<j;
            return 0;
            }
            x++;
            i++;
            y=(!y);
        }
        x++;
    }
    return 0;
}

