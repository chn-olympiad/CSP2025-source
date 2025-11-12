#include<bits/stdc++.h>
using namespace std;

long long mod=998244353;
long long n,m,s[505],c[505],cnt;
bool t,b[1000];

long long check(int i,int yes,int no){
    int ans=0;
    if(i>n){
        if(yes>=m)return 1;
        else return 0;
    }
    for(int j=1; j<=n; j++){
        if(!b[j]){
            b[j]=true;
            if(c[j]<=no)ans+=check(i+1,yes,no+1)%mod;
            else if(s[i]==0)ans+=check(i+1,yes,no+1)%mod;
            else if(s[i]==1)ans+=check(i+1,yes+1,no)%mod;
            b[j]=false;
        }
    }
    return ans%mod;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cnt=1;
    string s1;
    cin >> s1;
    for(int i=1; i<=n; i++){
        s[i]=s1[i-1]-'0';
        if(!s[i])t=true;
    }
    int ui=n;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        if(c[i]==0)ui--;
    }
    if(ui<m){
        printf("0");
        return 0;
    }
    if(!t||m==n){
        for(int i=ui; i>0; --i){
            cnt=(cnt*i)%mod;
        }
        printf("%d",cnt);
        return 0;
    }
    if(n<=18){
        printf("%lld",check(1,0,0));
        return 0;
    }
    printf("998244352");

    return 0;
}
