#include<bits/stdc++.h>

using namespace std;
int n,m,a[105],rgrade,b[15][15],cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    rgrade=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    //for(int i=1;i<=n*m;i++){
    //    cout<<a[i]<<" ";
    //}
    //cout<<endl;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=a[++cnt];
                //cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
            }
        }else{
            for(int i=n;i>=1;i--){
                b[i][j]=a[++cnt];
                //cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //cout<<b[i][j]<<" ";
            if(b[i][j]==rgrade){
                cout<<j<<" "<<i;
                break;
            }
        }
        //cout<<endl;
    }
    //int c=(p/(n-1)),r;
    //if(c%2==1){
    //    r=p-n*(p/(n-1))-1;
    //}else{
    //    r=n-(p-n*(p/(n-1)))-1;
    //}
    //cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
4 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
