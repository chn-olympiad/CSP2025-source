#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    bool f1=1,f2=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f1=0;
        }
        if(a[i]>1||a[i]<0){
            f2=0;
        }
    }
    if(f1){
        if(k==0){
            cout<<n/2<<endl;
        }
    }
    else if(f2){
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0&&b[i]==0){
                    b[i]=1;
                    ans++;
                }
                else if(a[i]==1&&a[i+1]==1&&b[i]==0&&b[i+1]==0&&i+1<=n){
                    ans++;
                    b[i]=1;
                    b[i+1]=1;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}
