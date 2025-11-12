#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,x=0,y=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        int b[i];
        while(i+y<=n){
            for(int j=y;j<=i+y;j++){
                x=x+a[j];
                b[j]=a[j];

            }
            cout<<x<<' ';
            //for(int j=0;j<i-1;j++){
              //  for(int j=0;j<i-1;j++){
                //    if(b[j]<b[j+1]){
                  //      swap(b[j],b[j+1]);
                    //}
                //}
            //}
            //if(x>2*b[0]){
              //  ans++;
            //}
            x=0;
            y++;
            }
            x=0;
            y=0;
    }
    //cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
