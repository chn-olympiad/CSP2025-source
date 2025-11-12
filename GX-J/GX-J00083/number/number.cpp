#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string zfc,hzf;
    cin>>zfc;
    long long c,h=0;
    c=zfc.size();
    for(int i=0;i<c;i++){
        if(zfc[i]>='0' && zfc[i]<='9'){
            hzf[h]=zfc[i];
            h++;
        }
    }
    int s=9;
    for(int i=0;i<10;i++){
        for(int j=0;j<h;j++){
            if(int(hzf[j])-48==s){
                cout<<hzf[j];
            }
        }
        s--;
    }
    return 0;
}
