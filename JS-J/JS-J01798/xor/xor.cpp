#include<bits/stdc++.h>
using namespace std;
map<int,bool>mp;
int n,k,a[500100],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)a[i]=a[i]^a[i-1];
    mp[0]=1;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<' ';
        if(mp[k^a[i]])ans++,mp.clear();
        mp[a[i]]=1;
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
