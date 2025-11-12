#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],zmap[11][11],c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
        int ma=1;
        for(int j=1;j<=n*m;j++){
            if(a[j]>a[ma])ma=j;

        }
        a[ma]=0;
        bool yes=0;
        for (int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(zmap[i][j]==0){
                    zmap[i][j]=ma;
                    if(ma==1){
                        c=i;
                        r=j;
                    }
                    yes=1;
                    break;
                }
            }
            if(yes)break;
        }
    }
    if(c%2==0) r=1+n-r;
    cout<<c<<" "<<r;
    return 0;
}
