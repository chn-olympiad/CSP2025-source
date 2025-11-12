#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
int n,m;
int a[100005];
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+m);
    int f=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            f=1;break;
        }
    }
    int ans=0;
    for(int i=m;i<=n;i++){
        ll sum=1;
        for(int j=i;j>=1;j--){
            sum*=j;
            sum%=998244353;
        }
        ans+=sum;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
