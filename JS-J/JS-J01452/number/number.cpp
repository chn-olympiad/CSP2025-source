#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int m=0;
    int l[1000000]={};
    cin>>a;
    int y=a.length();
    for(int i=1;i<=y;i++){
        l[i-1]=a[i-1];
        m++;
    }
    for(int i=58;i>=48;i--){
        for(int j=1;j<=m;j++){

            if(l[j-1]==i){
                cout<<l[j-1]-48;
            }
        }

    }

}
