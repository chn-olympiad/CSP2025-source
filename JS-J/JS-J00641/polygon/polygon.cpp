#include<bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
int cw[5005],sum=0,ma=0,tmp=0,n,js=0;
void ss(int c){
    if(c>n){
        if(sum>ma*2&&js>=3){
            tmp++;
            tmp=tmp%MAXN;
        }
        return ;
    }
    for(int i=0;i<=1;i++){
        if(i){
            js++;
            int sb=ma;
            sum+=cw[c];
            ma=max(ma,cw[c]);
            ss(c+1);
            ma=sb;
            sum-=cw[c];
            js--;
        }
        else ss(c+1);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cw[i];
    }
    ss(1);
    cout<<tmp;
    return 0;
}
