#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505],ans=0,path[505];
bool ff[505];
void f(int pos){
    if(pos==n+1){
        int unpass=0,pass=0;/*
        for(int i=1;i<=n;i++){
            cout<<path[i];
        }
        cout<<endl;*/
        for(int i=1;i<=n;i++){
            if(path[i]<=unpass||s[i-1]=='0'){
                unpass++;
            }else{
                pass++;
            }
        }
        if(pass>=m){
            ans++;
            ans%=MOD;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(ff[i]) continue;
        path[pos]=c[i];
        ff[i]=true;
        f(pos+1);
        ff[i]=false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    f(1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
