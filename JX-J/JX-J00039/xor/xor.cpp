#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans,b,num;
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                ans++;
                continue;
            }
            if(a[i]==a[i+1]){
                ans++;
                continue;
            }
        }
        cout<<ans;
    }else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                ans++;
                continue;
            }
            if((a[i]==a[i+1]+1||a[i]+1==a[i+1])&&a[i]!=0){
                ans++;
                continue;
            }
        }
        cout<<ans;
    }else{
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                ans++;
                continue;
            }
            for(int j=i;j<=n;j++){
                b=b^a[j];
                if(b==k){
                    ans++;
                    f=1;
                    num=j;
                    break;
                }
            }
            if(f==1) i=num;
            b=0;
        }
        cout<<ans;
    }
    return 0;
}
