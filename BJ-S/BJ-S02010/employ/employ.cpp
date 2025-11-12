#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#include<stdio.h>
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    bool nozero=true,allzero=true;
    int n,m,strzerocnt=0;
    size_t ans=1;
    cin>>n>>m;
    string str;
    cin>>str;
    for(size_t i=0;i<str.length();i++){
        if(str[i]=='0')strzerocnt++;
    }
    int c[n+1],pers[n+1];
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(!c[i])nozero=false;
        if(c[i])allzero=false;
        pers[i]=i;
    }
    if(n==m){
        if(!nozero){
            cout<<0;
            return 0;
        }else{
            for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
            cout<<ans;
        }
    }else if(m==1 || !strzerocnt){
        for(int i=1;i<=n;i++)ans=(ans*i)%998244353;
        cout<<ans;
    }else if(allzero){
        if(str[0]=='1')cout<<1;
        else cout<<0;
    }
    return 0;
}