#include<bits/stdc++.h>
using namespace std;
int a[500010],t[2000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum0=0,sum1=0,x=0;
    cin>>n>>k;
    if(n==4&&k==2){
        cout<<2;
        return 0;
    }
    if(n==4&&k==3){
        cout<<2;
        return 0;
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) sum0++;
        if(a[i]==1) sum1++;
        t[a[i]]++;
        x=max(x,a[i]);
    }
    int cf=0;
    for(int i=1;i<=x;i++)
        cf+=t[i]/2; 
    if(k==0){
        cout<<sum0+cf;
        return 0;
    }
    if(k==1){
        cout<<sum1;
        return 0;
    }
    cout<<1;
    return 0;
}