#include<bits/stdc++.h>
using namespace std;
string a;
int b[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;

    for(int i=0;i<sizeof(a);i++){
        if(a[i] - '0'>=0  or a[i] - '0'<=9){
            int j= a[i]-'0';
            b[j]++;
        }

    }
    for(int i=10;i>=0;i--){
        for(int j=0;j<b[i];j++){
            cout<<i;
        }
    }


    return 0;
}


