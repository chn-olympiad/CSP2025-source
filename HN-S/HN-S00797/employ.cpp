#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long fact(int n){
    long long ans=1;
    for(int i=2;i<=n;i++)ans=ans*i%mod;
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    int a[n],cnt[n+2]={};
    for(int i=0;i<n;i++)cin>>a[i],cnt[a[i]]++;
    if(n==m){
        if(count(s.begin(),s.end(),'0')>0||cnt[0]>0)cout<<"0\n",exit(0);
        cout<<fact(n),exit(0);
    }
    int ans=0,p[n];
    for(int i=0;i<n;i++)p[i]=i;
    while(1){
        int cnt=0,Cnt=0;
        for(int i=0;i<n;i++)
            if(s[i]=='1'&&a[p[i]]>cnt)Cnt++;
            else cnt++;
        ans+=Cnt>=m;
        if(!next_permutation(p,p+n))break;
    }
    cout<<ans;
    return 0;
}
