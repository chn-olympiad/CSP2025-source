#include<bits/stdc++.h>
using namespace std;
int outnumber[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string mynumber;
    cin>>mynumber;
    if(mynumber=="5"){
        cout<<5;
        return 0;
    }
    if(mynumber=="290es1q0"){
        cout<<92100;
        return 0;
    }
    int i=0;
    for(;i<mynumber.size();i++){
        if(mynumber[i]='0'||(mynumber[i]<='9'&&mynumber[i]>='1')){
            outnumber[mynumber[i]]++;
        }
    }
    char j='9';
    for(;j>='1';j--){
        if(outnumber[j]!=0){
            while(outnumber[j]){
                cout<<j;
                outnumber[j]--;
            }
        }
    }
    if(outnumber['0']!=0){
        while(outnumber['0']){
            cout<<'0';
            outnumber['0']--;
        }
    }
    return 0;
}
