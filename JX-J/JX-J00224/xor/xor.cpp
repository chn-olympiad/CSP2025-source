#include<bits/stdc++.h>
using namespace std;
int n,k,b[1005],a[1005][1005],cnt,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=a[i][j-1]^b[j];
            if(a[i][j]==k){
                ans++;
            }
        }
    }
    if(k==0){
        cout<<ans+1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    /*if(k==1){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i][j]==0){
                    cnt++;
                }
            }
        }
        cout<<cnt+1<<endl;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[i][j]==0){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        return 0;
    }*/
    return 0;
}

