#include<bits/stdc++.h>
using namespace std;
int a[500005],f[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag=0;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=1;
    }
    if(k==0){
        if(flag==0) cout<<n/2;
        else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0) cnt++;
                else if(a[i]==1 && a[i+1]==1 && i+1<=n){
                    cnt++;
                    i++;
                }
            }
            cout<<cnt;
        }
        return 0;
    }
    else if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt++;
            else if(a[i]==0 && a[i+1]==0 && i+1<=n){
                cnt++;
                i++;
            }
        }

        cout<<cnt;
        return 0;
    }
    int num=0,cnt=0;
    for(int i=1;i<=n;i++){
        num=num^a[i];
        if(num==k){
            cnt++;
            num=0;
        }
    }
    cout<<cnt;
    return 0;
}
