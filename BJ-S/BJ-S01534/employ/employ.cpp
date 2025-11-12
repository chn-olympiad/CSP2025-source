#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,re=0,t,is=1;
string s;
int c[5000001];
bool b[5000001];
void dfs(int de,int come,int go){
    if(de>n){
        if(come>=m){
            re++;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]){
            b[i]=1;
            if(go<c[i]&&((s[i-1]-'0')==1)){
                dfs(de+1,come+1,go);
            }else{
                dfs(de+1,come,go+1);
            }
            b[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=0;i<s.size();i++){
        if((s[i]-'0')==0){
            is=0;
        }
    }
    for(int i=0;i<=n;i++)
        b[i]=0;
    if(!is){
        dfs(1,0,0);
        cout<<re<<endl;
        return 0;
    }
    t=n;
    re=1;
    for(int i=1;i<=n;i++)
        if(!c[i])
            t--;
    if(m>t){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=t;i++){
        re*=i;
        re%=998244353;
    }
    cout<<re<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
