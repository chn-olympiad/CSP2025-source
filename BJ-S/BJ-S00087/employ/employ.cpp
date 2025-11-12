#include<bits/stdc++.h>
using namespace std;
int n,m,nx[500],rr[500],ans;
string nd;
void dg(int r[],int ok,int bok){
    if(bok>n-m){
        return;
    }
    if(bok+ok>=n){
        ans++;
        ans%=998244353;
        return;
    }
    for(int a=0;a<n;a++){
        if(r[a]==0){
            r[a]=1;
            if(nd[ok+bok]-'0'==1&&bok<nx[a]){
                dg(r,ok+1,bok);
            }else{
                dg(r,ok,bok+1);
            }
            r[a]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>nd;
    for(int a=0;a<n;a++){
        cin>>nx[a];
    }
    dg(rr,0,0);
    cout<<ans;
    return 0;
}