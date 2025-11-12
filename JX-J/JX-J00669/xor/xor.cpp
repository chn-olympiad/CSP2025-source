#include<bits/stdc++.h>
using namespace std;
int cz(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    int a,b,c[10000]={0},d=0;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
        if(c[i]==b){
            d++;
        }
    }
    for(int i=0;i<a-1;i++){
        for(int j=i+1;j<a;j++){
            if((c[i]+c[j]==b || cz(c[i],c[j])==b) && c[i]*c[j]!=0){
                d++;
            }
        }
    }
    cout<<d;
    return 0;
}
