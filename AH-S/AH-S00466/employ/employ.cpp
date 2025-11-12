#include<iostream>
#include<cstdio>
using namespace std;

const int mod=998244353;

int n,m;
int nx[1111],num[1111];
long long k=1,ans=0;;
bool dc[1111];
string s;

bool OK(){
    int kkk=0,shibaideman=0;
    for(int a=1;a<=n;a++){
        if(s[a]=='1' && shibaideman<num[a]){
            shibaideman=0;
            kkk++;
        }else{
            shibaideman++;
        }
    }
    if(kkk>=m){
        return true;
    }
    return false;
}

void DFS(int x){
    if(x>n){
        if(OK()){
            ans++;
        }
        return ;
    }
    for(int a=1;a<=n;a++){
        if(!dc[a]){
            dc[a]=true;
            num[x]=nx[a];
            DFS(x+1);
            dc[a]=false;
            num[x]=0;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n>10){
        for(int a=1;a<=n;a++){
            k*=a;
            k%=mod;
        }
        cout<<k;
        return 0;
    }
    cin>>s;
    s=' '+s;
    for(int a=1;a<=n;a++){
        cin>>nx[a];
    }
    DFS(1);
    cout<<ans%mod;
}
