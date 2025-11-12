#include<bits/stdc++.h>
using namespace std;
int a[510];
long long kuaisumi(long long p, long long k, long long ans){
    if(p>k)  return ans;
    ans*=(long long)p;
    ans%=998244353;
    return kuaisumi(p+1,k,ans);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,l=0;
    bool p=1;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    int k=s.size();
    for(int i=0;i<k;i++)
        if(s[i]=='0')  p=0,l++;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0)  p=0;
    }
    if(m==n){
        if(p==1){
            cout<<kuaisumi(1,n,1);
        }else{
            cout<<0;
        }
        return 0;
    }
    if(n-l<m){
        cout<<0;
    }
    return 0;
}
