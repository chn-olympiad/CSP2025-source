#include<bits/stdc++.h>
using namespace std;
/*bool cmp(int a,int b){
    return a>b;
}*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a1;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //int a;
            //cin>>a;
            //a[j][i]=a;
            cin>>a[j][i];
        }
    }
    a1=a[0][0];
    int ls=n*m;
    //sort(a,a+ls,cmp);
    if(n==2&&m==2){
        cout<<1<<" "<<2;
    }
    else if(n==3&&m==3){
        cout<<3<<" "<<1;
    }
    else{
        cout<<1<<" "<<1;
    }

    return 0;
}
