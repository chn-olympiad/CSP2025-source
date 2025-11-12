#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10;
const int mod=998244353;
int a[maxn],b[maxn],c[maxn],d[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,num=0;
    long long ans=1;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        a[i]=s[i]-'0';
        if(a[i])num++;
        c[i]=a[i]^1;
        if(i>0)c[i]=a[i]^1+c[i-1];
    }
    if(num==n){
        if(n==m){
            for(int i=2;i<=n;i++){
            ans=ans*i;
            ans%=mod;
            }
        }
        else ans=0;
        cout<<ans;
        return 0;
    }
    if(m>num){cout<<0;return 0;}
    for(int i=0;i<n;i++){
        cin>>b[i];
        d[i]=b[i];
    }
    sort(b,b+n,cmp);
    long long ans2=0;
    do{
        int cnt=0;
        for(int i=0;i<n;i++)b[i]=d[i];
        for(int i=0;i<n,cnt<=m;i++)
        {
            if(a[i]==1&&d[i]>0){
                cnt++;
            }
            if(a[i]==0){
                for(int j=i;j<n;j++)
                    d[j]--;
            }
        }
        if(cnt==m)ans2++;
    }
    while(next_permutation(b,b+n));
    cout<<ans2;
    return 0;
}

