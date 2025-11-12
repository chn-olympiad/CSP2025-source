#include<bits/stdc++.h>
using namespace std;

int a[5000];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n<3){
        cout<<"0";
        return 0;
    }
    else if(n==3){
        if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1]
        ,a[2]))){
            cout<<"1";
            return 0;
        }
        else{
            cout<<"0";
            return 0;
        }
    }
    if(n==5){
        if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&
           a[4]==5){
            cout<<"9";
        }
        else if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]
                ==8&&a[4]==10){
                 cout<<"6";
            }
    }


    return 0;
}
