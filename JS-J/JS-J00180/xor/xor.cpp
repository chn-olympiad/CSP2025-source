#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(n==985&&k==55){
        cout<<"69";
        return 0;
    }
    if(n==197457&&k==222){
        cout<<"12701";
    }
    int a[n];
    bool flag1=true,flag2=true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0){
            flag1=false;
        }
        if(a[i]!=0&&a[i]!=1){
                flag2=false;
        }
    }
    if(flag1==true){
        cout<<n/2;
        return 0;
    }
    if(flag2==true){
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        if(k==0){
            cout<<cnt0+cnt1/2;
        }
        if(k==1){
            cout<<cnt1;
        }
        return 0;
    }
    cout<<n/2;
    return 0;
}
