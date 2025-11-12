#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,k;
ll a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    //cout<<~4;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll tmp=a[1];
    for(int l=1,r=1;l<=n && r<=n;){
        //cout<<l<<" "<<r<<" "<<tmp<<endl;
        if(tmp==k){
            tmp^=a[l++];
            if(r<n)
                tmp^=a[++r];
            ans++;
            //cout<<"got!\n";
            continue;
        }
        else{
            if(r<n)
                tmp^=a[++r];
            else
                tmp^=a[l++];
        }

    }
    cout<<ans;
    return 0;
}
