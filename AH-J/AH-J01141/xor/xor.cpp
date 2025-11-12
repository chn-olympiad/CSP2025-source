#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    bool f=1,o=0,z=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        o+=(a[i]==1);
        z+=(a[i]==0);
        if(a[i]!=1) f=0;
    }
    if(f){
        if(k==0) cout<<n/2;
        else if(k==1) cout<<n;
        else cout<<0;
    }else{
        if(o+z==n&&(k==0||k==1)){
            if(k==0){
                int cnt=0;
                a[n+1]=!a[n];
                for(int i=1;i<=n;i++){
                    if(a[i]==0){
                        cnt++;
                    }else if(a[i]==a[i+1]){
                        cnt++;
                        i++;
                    }
                }
                cout<<cnt;
            }else{
                int cnt=0;
                a[n+1]=a[n];
                for(int i=1;i<=n;i++){
                    if(a[i]==1){
                        cnt++;
                    }else if(a[i]!=a[i+1]){
                        cnt++;
                        i++;
                    }
                }
                cout<<cnt;
            }
        }else{
            int sum=0,ans=0;
            int l=1;
            for(int r=1;r<=n;r++){
                sum^=a[r];
                while(sum>k&&l<r){
                    sum^=a[l];
                    l++;
                }
                if(sum==k){
                    ans++;
                    l=r+1;
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
