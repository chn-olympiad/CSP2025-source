#include<bits/stdc++.h>
using namespace std;
int a[200005],ans1,ans2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)ans1++;
        if(a[i]==0)ans2++;
    }
    if(ans1==n){
        cout<<n/2;
    }else if(ans1+ans2==n){
        if(k==1)cout<<ans1;
        else {
            int ans3=0;
            for(int i=0;i<n-1;i++){
                if(a[i]==1&&a[i+1]==1){
                    ans3++;
                    i++;
                }
            }
            cout<<ans2+ans3;
        }
    }
    return 0;
}
