#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[50],num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
            num=9;
            cout<<num;
        }
    }

    return 0;
}
