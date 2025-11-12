#include<bits/stdc++.h>
using namespace std;
const int N=1e+6;
int stick[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n,m=0;
    for(int i=1;i<=n;i++){
        cin>>stick[i];
    }
    if(stick[1]+stick[2]+stick[3]>stick[1]*2&&stick[1]+stick[2]+stick[3]>stick[2]*2&&stick[1]+stick[2]+stick[3]>stick[3]*2){
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
