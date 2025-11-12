#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],s[15][15],nn,nm,cc,ansn,ansm,ans;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    ans=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }

    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){

        if(nn==n){
            nm++;
            cc=1;
        }
        if(nn==1){
            nm++;
            cc=0;
        }
        if(cc==0) nn++;
        if(cc==1) nn--;
        s[nn][nm]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==ans){
                ansn=i;
                ansm=j;
            }
        }
    }
    cout<<ansn<<" "<<ansm;
    return 0;
}
