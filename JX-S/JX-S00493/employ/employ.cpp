#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector<int>
#define vl vector<long long>
const int N=500+10;
const ll MOD=998244353;
int n,m,a[N];
ll ans=0;
string s;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("employ.in","r",stdin);//please open it
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    ans=1;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int len=s.length();
    for(int i=0;i<n;i++){
        if(s[i]==0){
            cout<<0;
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if((a[i]-i)+1<0){
            cout<<0;
            return 0;
        }
        if((a[i]-i+1)>=2&&(a[i-1]-i)>=2)cnt++;
    }
    for(int i=cnt;i>=1;i--){
        ll tot=i;
        for(int j=i-1;j>=1;j--){
            tot*=j;
            tot%=MOD;
        }
        if(tot==0)tot=1;
        ans+=tot;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}

