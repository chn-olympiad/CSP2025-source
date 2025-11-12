#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt[500005],cntt[500005],cnt1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cntt[a[i]]==0&&a[i]!=0){
            cntt[a[i]]=cnt[a[i]]/2;
            cnt1+=cntt[a[i]];
        }
    }
    if(k==0) cout<<cnt[0]+cnt1<<endl;
    else cout<<cnt[k]<<endl;
    return 0;
}
