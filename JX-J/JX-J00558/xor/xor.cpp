#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long tot=0,cnt=0,st[500005];
unordered_map<long long,long long>mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i]^k;
        //cout<<b[i]<<" ";
    }
    //cout<<endl;
    for (int i=1;i<=n;++i){

        if (!b[i]){
            mp.clear();
            ++cnt;
            tot=0;
            continue;
        }
        //cout<<tot<<" ";
        if (tot){

            if (mp[a[i]]){

                ++cnt,tot=0;
                //cout<<cnt;
                mp.clear();
                continue;
            }
            else {
                mp.clear();
                for (int j=1;j<=tot;++j){
                    st[j]^=a[i];
                    mp[st[j]]=j;
                }

            }
        }
        st[++tot]=b[i];
        mp[st[tot]]=tot;
    }
    cout<<cnt;
    return 0;
}
