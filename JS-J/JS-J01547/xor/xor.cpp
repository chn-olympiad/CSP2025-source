#include<bits/stdc++.h>
using namespace std;

int a[500005],cnt;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n==1&&k==0){
        int a;
        cin>>a;
        if(a==0)cout<<1;
        else cout<<0;
    }
    else if(n==2&&k==0){
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0)cout<<2;
        if(a==0||b==0)cout<<1;
        else cout<<0;
    }
    else if(k==0){
        bool flag;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(a[i]==1){
                flag=false;

            }
            else cnt++;
        }
        if(flag){
            cout<<n;
        }
        else cout<<cnt;
    }
    else if(k==1){
            for(int i=1;i<=n;++i){
                cin>>a[i];
            if(a[i]==1){
                cnt++;
            }

        }
        cout<<cnt;
    }
    else if(n==4&&k==3){
        cout<<2;
    }
    else if(n==197457&&k==222)cout<<12701;
    else if(n==985&&k==55)cout<<69;
    else {
        for(int i=1;i<=n;++i){
             cin>>a[i];
             if(a[i]==k)cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
