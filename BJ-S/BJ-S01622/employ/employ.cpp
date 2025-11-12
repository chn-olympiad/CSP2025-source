#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q,a[maxn],b[maxn],c[maxn],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        char k; cin>>k;
        if(k=='0') a[i]=0;
        else a[i]=1;
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    int len=1;
    for(int i=1;i<=n;i++) len*=i;
    for(int s=1;s<=len;s++){
        int no=0,l=0;
        for(int i=1;i<=n;i++){
            if(a[i] && b[i]>no) l++;
            else no++;
        }
        if(l>=q) ans++;
        next_permutation(b+1,b+1+n);
    }
    cout<<ans<<endl;
    return 0;
}
