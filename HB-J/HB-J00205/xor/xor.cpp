#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,flag=1,ansa=0;
    cin>>n>>k;
    int a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)flag=0;
        if(flag){
            if(a[i])ansa++;
        }
    }
    if(flag){
        if(k==1)cout<<ansa;
        else cout<<n-ansa;
    }
    else{

    }
    return 0;
}
//luogu:1073546
//time:20251101
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
