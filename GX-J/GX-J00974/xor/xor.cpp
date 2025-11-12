#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    bool Apts=true,Bpts=true;
    int NumOne=0,NumTwo=0;
    if(k!=0) Apts=false;
    if(k>1) Bpts=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) Apts=false;
        if(a[i]>1) Bpts=false;
        if(a[i]==1) NumOne++;
        if(a[i]==0) NumTwo++;
    }
    if(Apts){
        cout<<n/2;
        return 0;
    }
    else if(Bpts){
        if(k==0){
            cout<<(NumOne/2);
        }
        else{
            cout<<min(NumOne,NumTwo)/2;
        }
        return 0;
    }
    return 0;
}
