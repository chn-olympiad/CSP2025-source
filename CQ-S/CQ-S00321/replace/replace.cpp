#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
map<pair<int,int>,pair<int,int>> mp;
string s1[N],s2[N];
struct noid{
    int l,r,mid;
}a[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int nn=s1.size();
        for(int j=0;j<nn;j++){
            if(s1[j]=='b'){
                a[i].l=j;
                a[i].r=n-j-1;
            }
        }
        for(int j=0;j<nn;j++){
            if(s2[j]=='b'){
                a[i].mid=j-a[i].l;
            }
        }
    }
    while(q--){
        string tj1,tj2;
        cin>>tj1>>tj2;
        int nn=tj1.size();
        int cz,wz;
        for(int i=0;i<nn;i++){
            if(tj1[i]=='b'){
                cz=i;
                wz=i;
            }
        }
        for(int i=0;i<nn;i++){
            if(tj2[i]=='b'){
                cz=i-cz;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].mid==cz&&a[i].l<=i&&a[i].r<=nn-wz-1){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
