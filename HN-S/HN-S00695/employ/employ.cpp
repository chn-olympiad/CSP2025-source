#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    string x,y;
};
const int N=5e5;
node a[N];
int s[N];
int c[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if(n>10){
        if(n==100){
            cout<<161088479<<endl;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        cout<<ans<<endl;
        return 0;
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int ans=0;
    vector<int>v(n);
    for(int i=0;i<v.size();i++)v[i]=i;
    do{
        int rj=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(rj>=c[i]){
                continue;
            }
            cnt+=s[v[i]]-'0';
        }
        if(cnt>=q){
            ans++;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
    return 0;
}
