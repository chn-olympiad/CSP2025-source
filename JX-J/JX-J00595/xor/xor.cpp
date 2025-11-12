#include<bits/stdc++.h>
using namespace std;
int a[500010]={-1};
int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
    }
    int s;
    for(int l=1;l<=n;l++){
            s=a[l];
            if(s==-1)continue;
        for(int r=l+1;r<=n;r++){
                s^=a[r];
                if(s==k){
                    ans++;
                    l=r+1;
                    break;
                }
        }
    }
    cout<<ans;
    return 0;
}
