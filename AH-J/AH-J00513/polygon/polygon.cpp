#include<bits/stdc++.h>
using namespace std;
long long n,m,xb=0,a[200],cnt,f=0,ACNT=0;
string s;
long long slen;
long long dg(long long ii,long long max_,long long he){
    if(ii==n){
        if(max_*2<he&&he>0&&max_>0){
            cnt++;
            cnt=cnt%998244353;
        }
        return 0;
    }
    dg(ii+1,max(max_,a[ii+1]),he+a[ii+1]);
    dg(ii+1,max_,he);
}
long long AC(long long ii,long long many){
    if(ii==n){
        if(many>=3){
            ACNT++;
            ACNT=ACNT%998244353;
        }
        return 0;
    }
    AC(ii+1,many+1);
    AC(ii+1,many);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=1){
                f=1;
            }
    }
    if(f==1){
        dg(0,0,0);
        cout<<cnt;
    }else{
        AC(0,0);
        cout<<ACNT;
    }
    return 0;
}


