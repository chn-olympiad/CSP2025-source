#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=998244353;
int a[N];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,k;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        cout<<1<<'\n';
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') k++;
    }
    sort(a+1,a+n+1);
    int b=0,ans=0;
    for(int i=0;i<n;i++){
        int k=s[i]-'0';
        if(k==0){
            b++;
            continue;
        }
        while(b>a[k]&&k<=n){
            k++;
        }
        if(k>n) break;
        ans++;
        if(ans==m) break;
    }
    long long cnt=1;
    for(int i=2;i<=n;i++){
        cnt=(cnt*i)%M;
    }
    if(n-k!=0) cnt=(n-k)*cnt/2%M;
    cout<<cnt<<'\n';
    return 0;
}
