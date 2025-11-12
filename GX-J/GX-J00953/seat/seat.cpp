#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[100][100],c=0,q=1,e=1,r=0,t=0;
            cin>>n>>m;
    for(int i=1;i<=n;i++){
            if(i%2==0){
                for(int j=m;j>=1;j--){
                cin>>a[i][j];
    }
            }else{
            for(int j=1;j<=m;j++){
            cin>>a[i][j];
    }
            }

}
        c=a[1][1];
    for(int i=1;i<=n;i++){
            if(i%2==0){
                for(int j=m;j>=1;j--){
            if(a[q][e]<a[i][j]){
                    r=q;
                    t=e;
                    q=i;
                    e=j;
        swap(a[r][t],a[i][j]);
        }

            }

            }else{
                for(int j=1;j<=m;j++){
            if(a[q][e]<a[i][j]){
                    r=q;
                    t=e;
                    q=i;
                    e=j;
        swap(a[r][t],a[i][j]);
            }
        }
    }

}
    cout<<q<<" "<<e;
return 0;
}
