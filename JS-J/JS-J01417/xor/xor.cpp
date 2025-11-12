#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,s;
    int y[2000000];
    int h[2000000]={0};
    cin>>a>>s;
    for(int i=0;i<a;i++){
        cin>>y[i];
        while(y[i]!=1){
            int o=-1;
            int u=2;
                while(u<y[i]){
                   u*=2;
                   o++;
                }
                y[i]-=u/2;
                h[i]+=pow(10,o);
        }
    }
    for(int i=0;i<a;i++){
        cout<<h[i]<<' ';
    }

    return 0;
}
