#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]==0)
            cnt1++;
        if (a[i]==1)
            cnt2++;
    }
    if (k==0 && cnt1==n)
        cout<<n;
    else if (k==0 && cnt2==n)
        cout<<n/2;
    else if (k==1 && cnt2==n)
        cout<<n;
    else if (k==1 && cnt1==n)
        cout<<n/2;
    else if (k==0){
        int ans=0,flag=0;
        for (int i=1;i<=n;i++){
            if (a[i]==0)
                ans++;
            else{
                if (i+1<=n && a[i+1]==1){
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans;
    }
    else if (k==1){
        int ans=0,flag=0;
        for (int i=1;i<=n;i++){
            if (a[i]==1)
                ans++;
        }
        cout<<ans;
    }
    return 0;
}
