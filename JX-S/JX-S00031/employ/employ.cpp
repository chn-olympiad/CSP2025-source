#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m;
ll cnt1,cnt2,ans;
char s[N];
ll a[N],b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ3.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=='1') cnt1++;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) cnt2++;
        b[a[i]]++;
    }
    if(cnt1<m || cnt2>n-m){
        cout<<0;
        return 0;
    }
    return 0;
}
