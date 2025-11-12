#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],xo[N],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xo[i]=(xo[i-1]^a[i]);
        //cout<<xo[i]<<' ';
    }
    //cout<<'\n';
    for(int i=1,j=1;i<=n;++i){
        int l=j;
        while((xo[i]^xo[j-1])!=k&&j<=i)j++;
        if((xo[i]^xo[j-1])==k&&j<=i){
            ans++;
            //cout<<j<<' '<<i<<'\n';
            j++;
        }else j=l;
    }
    cout<<ans;
    return 0;
}
