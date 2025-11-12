#include <bits/stdc++.h>

using namespace std;

char lst[1000001];
int hax[10];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    bool f=0;
    //string sout="";
    cin>>lst;
    for(int i=0; i<strlen(lst); i++){
        if('0'<=lst[i]&&lst[i]<='9'){
            hax[lst[i]-'0']++;
        }
    }
    for(int i=0; i<=9; i++){
        if(hax[i]>0){
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<0;
    }else{
        for(int i=9; i>=0; i--){
            for(int j=0; j<hax[i]; j++){
                //sout+=char(i+'0');
                cout<<i;
            }
        }
        //cout<<sout;
    }
    return 0;
}
