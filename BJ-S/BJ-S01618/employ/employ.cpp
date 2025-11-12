/*
Ren5Jie4Di4Ling5%
*/
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string sa;
int c[505];
int vis[505];
int sum;
int ans[505];
int ansi;
void dfs(int s,int lys,int fail,int day){
    if(s==0){
        if(lys>=m){
            sum=(sum+1)%MOD;
        }
        //for(int i=0;i<ansi;i++){
            //cout<<ans[i];
        //}
        //cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(fail>=c[i]||sa[day]=='0'){
                //ans[ansi++]=0;
                dfs(s-1,lys,fail+1,day+1);
                //ansi--;
            }else{
                //ans[ansi++]=i+1;
                dfs(s-1,lys+1,fail,day+1);
                //ansi--;
            }
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>sa;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int isallone=1;
    for(int i=0;i<sa.length();i++){
        if(sa[i]=='0'){
            isallone=0;
            break;
        }
    }
    if(isallone==1){
        for(int i=0;i<n;i++){
            if(c[i]!=0){
                sum++;
            }
        }
        int ans=1;
        while(sum!=1){
            ans=(sum*(ans%MOD))%MOD;
            sum--;
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(n,0,0,0);
    cout<<sum<<endl;
    return 0;
}
