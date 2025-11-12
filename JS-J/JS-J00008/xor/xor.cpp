#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int mx=0;
void dfs(int l,int cnt){
    if(l>=n){
        mx=max(mx,cnt);
        return;
    }
    for(int i=l;i<n;i++){
        int gg=a[l];
        for(int j=l+1;j<=i;j++){
            gg=(gg^a[j]);
        }
        if(gg==k){
            dfs(i+1,cnt+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool flag=true;
    bool flag1=true;
    int ans0=0,ans1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)ans0++;
        else if(a[i]==1)ans1++;
        if(a[i]!=1){
            flag=false;
        }
        if(a[i]!=1||a[i]!=1){
            flag1=false;
        }
    }
    if(k==0&&flag){
        cout<<n/2;
        return 0;
    }
    if(k<=1&&flag1&&n>10){
        if(ans0==ans1){
            if(ans0%2==0){
                cout<<n/2;
                return 0;
            }
            else{
                if(k==1){
                    cout<<n/2;
                    return 0;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
        }
        else if(ans0>ans1){
            if(k==0){
                if(ans1%2==1){
                    cout<<0;
                    return 0;
                }
                else{
                    cout<<ans0+ans1/2;
                    return 0;
                }
            }
            else{
                cout<<ans1;
                return 0;
            }
        }
        else{
            if(k==0){
                if(ans1%2==0){
                    cout<<ans0+ans1/2;
                    return 0;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<ans1;
                return 0;
            }
        }
    }
    dfs(0,0);
    cout<<mx;
    return 0;
}
