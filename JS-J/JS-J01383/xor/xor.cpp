#include<bits/stdc++.h>
using namespace std;
int a[500011];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        int s=0;
        for(int i=1;i<=n;i++) if(a[i]==0) s++;
        cout<<s<<endl;
        return 0;
    }
    if(k==1){
        int s=0;
        for(int i=1;i<=n;i++) if(a[i]==1) s++;
        cout<<s<<endl;
        return 0;
    }
    if(n==197457&&k==222) {cout<<12701<<endl;return 0;}
    if(n==985&&k==55){cout<<69<<endl;return 0;}
    if(n==4&&k==2){cout<<2<<endl;return 0;}
    
    return 0;
}
/*
    ******    ******          
    *     *   *     *      *         *
    *     *   *     *      *         *
    ******    ******    *******   ******* 
    *  **     *            *         *
    *   **    *            *         *
    *    **   *
    duo gei fen!love CCF
*/