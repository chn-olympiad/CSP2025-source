#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a1=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)
            a1++;
    }
    if(a1==n)
        cout<<n/2;
    else{
        int ans=0;
        for(int i=1;i<n;i++)
            if(a[i]==1&&a[i+1]==0||a[i]==0&&a[i+1]==1)
                ans++,i++;
        cout<<ans;
    }
    return 0;
}
