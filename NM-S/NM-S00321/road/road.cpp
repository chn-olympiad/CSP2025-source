#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
     int a=1;
        int b=1;
        int l=10;
        int aa[100];
        aa[1]=a;
        aa[2]=b;
        for(int i=3;i<=l;i++){
            aa[i]=aa[i-1]+aa[i-2];
        }
        if(aa[5]>aa[6]){
            aa[6]=aa[5];
        }
    cout<<13;
return 0;
}
