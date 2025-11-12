#include<bits/stdc++.h>
using namespace std;
void runn(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,fla2=1,fla1=1;
    cin>>n;
    int a[n+10][7],b[n+1][3];
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
        cin>>a[i][2];
        cin>>a[i][3];
        if(a[i][1]>a[i][2]){
            if(a[i][2]>a[i][3]){
                b[i][1]=3;
                b[i][2]=2;
                b[i][3]=1;
            }
            else if(a[i][3]>a[i][1]){
                b[i][1]=2;
                b[i][2]=1;
                b[i][3]=3;
            }
            else{
                b[i][1]=2;
                b[i][2]=3;
                b[i][3]=1;
            }
        }
        else{
            if(a[i][1]>a[i][3]){
                b[i][1]=3;
                b[i][2]=1;
                b[i][3]=2;
            }
            else if(a[i][3]>a[i][2]){
                b[i][1]=1;
                b[i][2]=2;
                b[i][3]=3;
            }
            else{
                b[i][1]=1;
                b[i][2]=3;
                b[i][3]=2;
            }
        }
        if(a[i][2]){
            fla1=0;
            if(a[i][3]){
                fla2=0;
            }
        }
    }
    if(n==2){
        if(b[1][3]!=b[2][3]){
            cout<<a[1][b[1][3]]+a[2][b[2][3]];
        }else{
            cout<<max(a[1][b[1][2]]+a[2][b[2][3]],a[1][b[1][3]]+a[2][b[2][2]]);
        }
    }
    if(fla1==1){
        for(int i=1;i<=n;i++){
            
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        runn();
    }
}