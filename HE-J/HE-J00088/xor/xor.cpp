#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,cnt1;
int a[500005];
bool used[500005];
int r=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(used,false,sizeof(used));
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }
    }
    if(k==0 && cnt1==n){
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            cnt++;
            used[i]=true;
        }
    }
    for(int l=1;l<=n;l++){
        r=a[l];
        for(int i=l+1;i<=n;i++){
            if(used[i]==false){
                r=r^a[i];
                if(r==k){
                    cnt++;
                    for(int j=l;j<=i;j++){
                        used[j]=true;
                    }
                    break;
                }
            }else{
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
