#include<bits/stdc++.h>
using namespace std;
int t,temp[5][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        int a[20000][3],n;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        int maxa1=0,maxa2=0,maxa3=0;
        for(int i=0;i<n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                maxa1+=a[i][1];
            }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                maxa2+=a[i][2];
            }else{
                maxa3+=a[i][3];
            }
        }
        temp[i][1]=maxa1;
        temp[i][2]=maxa2;
        temp[i][3]=maxa3;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<t;j++){
            cout<<temp[i][j]<<endl;
        }
    }
    return 0;
}
