#include <bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int A(int a,int b){

    int res=1;
    for(int i=1;i<=b;i++){
        res*=a+1-i;res%=mod;
    }
    return res;
}
bool cmp(int a,int b){
    return a<b;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int fact[11]={1,1,2,6,24,120,720,5040,32400,362880,3628800};
    int n,m;
    cin>>n>>m;
    char s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    int c[n];
    for(int i=0;i<n;i++)cin>>c[i];
    if(n>10){
            if(n==m){
                bool flag=true;
        for(int i=0;i<n;i++)if(s[i]=='0'){
            flag=false;
            break;
        }
        if(flag)cout<<A(n,n);
        else cout<<0;
        return 0;
            }
        int tong[101];
        for(int i=0;i<n;i++){
            tong[c[i]]++;
        }
        int maxi=0,xxx=n;
        for(int i=0;i<=maxi;i++){
            maxi+=tong[i];
            xxx-=tong[i];
        }
        int ans=0;
        for(int i=m;i<=xxx;i++){
            ans+=A(xxx,i);
            ans%=mod;
        }
        cout<<ans;
        return 0;
    }
    int p[n],ans=0;
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=0;i<fact[n];i++){
        int cnt=0,yl=0;
        for(int j=0;j<n;j++){
            if(c[p[j]]<=yl)yl++;
            else if(s[j]=='0')yl++;
            else cnt++;
        }
        //cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
        if(cnt>=m)ans++;
        next_permutation(p,p+n,cmp);
    }
    cout<<ans;
    return 0;
}
//12pts
