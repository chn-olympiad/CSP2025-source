#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],b[15][15]={};
    cin>>n>>m;
    int z=n*m,c;
    for(int i=0;i<z;i++){
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+z);
    for(int i=z-1;i>=0;i--){
        //cout<<"paiming"<<a[i]<<' '<<z-i<<endl;
        if(c==a[i]){
            c=(z-i);
        }
    }
    //cout<<"c:"<<c<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j%2!=0) b[i][j]=(b[i][j-1]+1);
            else if(i==1 && j%2==0) b[i][j]=(b[i][j-1]+(n*2)-1);
            if(i>1 && j%2!=0) b[i][j]=(b[i-1][j]+1);
            else if(i>1 && j%2==0) b[i][j]=(b[i-1][j]-1);
            //cout<<"weizhi"<<i<<' '<<j<<' '<<b[i][j]<<endl;
            if(c==b[i][j]){
                cout<<j<<' '<<i<<endl;
            }
        }
    }

    return 0;
}
