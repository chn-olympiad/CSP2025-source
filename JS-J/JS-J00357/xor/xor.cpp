#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans1;
int ans0,ans11;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            ans1++;
        }
        else{
            ans0++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1&&a[i+1]==1){
            ans11++;
            i++;
        }
    }

    if(k==1){
        cout<<ans1;
    }
    if(k==0){
        cout<<ans0+ans11;
    }

    return 0;
}
