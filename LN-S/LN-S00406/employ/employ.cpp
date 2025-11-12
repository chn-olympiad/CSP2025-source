#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int A[505],used[505],c[505];
int n,m,cnt1=0,cnt2=0;
string s;
int dfs(int u,int sum){
    if(u==n+1){
        return sum>=m;
    }
    if(n-u+1+sum<m){
        return 0;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            res=(res+dfs(u+1,sum+(s[u-1]=='1'&&c[i]>(u-1-sum))))%P;
            used[i]=0;
        }
    }
    return res;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    A[1]=1;
    for(int i=2;i<=500;i++){
        A[i]=A[i-1]*i%P;
    }
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cnt1++;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0){
            cnt2++;
        }
    }
    if(m==n){
        if(cnt1>0||cnt2>0){
            cout<<0;
        }
        else{
            cout<<A[n];
        }
    }
    else if(cnt1==0){
        cout<<"&";
        if(n-cnt2<m){
            cout<<0;
        }
        else{
            cout<<A[n];
        }
    }
    else{
        cout<<dfs(1,0);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
