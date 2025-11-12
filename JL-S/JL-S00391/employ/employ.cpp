//20
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int a[1000],b[1000],t[1000];
bool f[1000];
void check(int k){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(t[i]<a[b[i]] && s[i-1]!='0'){
           sum++;
        }
    }
    if(sum==m){
        cnt++;
    }
}
void dfs(int n,int k){
    if(n<=k){
        for(int i=1;i<=k;i++){
            if(f[i]==false){
                b[n]=i;
                f[i]=true;
                dfs(n+1,k);
                f[i]=false;
            }
        }
    }else{
        check(k);
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    t[1]=s[1]-'0';
    for(int i=1;i<s.size();i++){
        if(s[i]=='1') t[i+1]=t[i];
        else t[i+1]=t[i]+1;
    }
    dfs(1,n);
    cout<<cnt;
    return 0;
}
