#include<bits/stdc++.h>
using namespace std;
int n,m,c[514],b[514],a[514];
const int mod=998244353;
string s;
inline int fac(int x){
    int asd=1;
    for(int i=1;i<=x;i++){
        asd*=i;
        asd%=mod;
    }
    return asd;
}
inline int dfs(int x){
    if(x==n+1){
        int sum=0,sum2=0;
        for(int i=1;i<=n;i++){
            if(c[b[i]]<=sum2||s[i-1]=='0'){
                sum2++;
            }else{
                sum++;
            }
        }
        return (sum>=m);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]){continue;}
        a[i]=1;
        b[x]=i;
        ans+=dfs(x+1);
        a[i]=0;
        b[x]=0;
    }
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            if(s[i-1]!='1'||c[i]==0){
                cout<<0;
                return 0;
            }
        }
        cout << fac(n);
        return 0;
    }
    bool flag=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]!='1'){
            flag=0;
            break;
        }
        if(c[i]==0){
            sum++;
        }
    }
    if(flag){
        cout<<fac(sum);
        return 0;
    }
    cout<< dfs(1);
    return 0;
}
