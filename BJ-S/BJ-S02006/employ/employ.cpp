#include <bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a[5005];
    long long ans=0;
    string s;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        ans=1;
        sort(a+1,a+n+1,cmp);
        int fq;
        for(int i=1;i<=n;i++){
            if(s[i]==48){
                break;
            }
            else if(fq>=a[i]){
                break;
            }
            else{
                ans*=i;
            }
        }
    }
    else if(m==n){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(s[i]==48){
                flag=0;
                ans=0;
                break;
            }
        }
        if(flag==1){
            ans=1;
        }
    }
    else{
        ans=m;
    }
    cout<<ans%MAXN;
    return 0;
}
