#include<bits/stdc++.h>
using namespace std;
bool maxx(int a,int b){
    if (a>b) {
        return a;
    }else return b;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    long long n,m,k,ds,l1,l2,l3;
    long long acc=0;
    long long da =0;
    cin>>n>>m>>k;
    int a1[k][n];
    int a2[k][n];

    for (int ma=1;ma<=m+1;ma++){
       for (int j2=1;j2<=3;j2++){
            cin>>l1>>l2>>l3;
            a2[l1][l2]=l3;
        }
    }
    for (int i=1;i<=m+1;i++){
        for (int j=1;j<=n;j++){
            cin>>a1[i][j-1];
        }
    }
    for (int i2=1;i2<=k;i2++){
        ds=0;
        int dd =0;
        for (int i3=1;i3<=n-1;i3++){
            if(a1[i2][i3]<=a2[i2][i3]||a1[i2][i3]<=a2[i3][i2]){
                acc = acc + a1[i2][i3];
            }
            if(a1[i2][i3]>a2[i2][i3]||a1[i2][i3]<=a2[i3][i2]){
                if (a2[i2][i3]>=a2[i3][i2]){
                    acc = acc+a2[i2][i3];
                    ds=1;
                }else {
                    acc = acc + a2[i3][i2];
                    dd = a2[i3][0];
            }
        }
        if (ds==1){
            if(da<acc+a2[i2][0]){
                da = acc+a2[i2][0];
            }
        }else{
            if(da<acc+dd){
                da = acc+dd;
            }
        }


    }
    }
    
    cout<<da;
    return 0;
}
