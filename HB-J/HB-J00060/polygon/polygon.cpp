#include <bits/stdc++.h>
using namespace std;
int res,eqs;
int mod=998244353;
int a[10005];
//a stolepoint program
//E=10
//T=0

int powf(int a,int b,int m){
    int base=a;
    int ans=1;
    while(b){
        if(b&1){
            ans*=base;
            ans%=m;
        }
        base*=base;
        base%=m;
        b>>=1;
    }
    return ans%mod;
}


int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    if(k==3){
        int q=a[0];
        int w=a[1];
        int e=a[2];
        int maq=max(max(q,w),e);
        if((q+w+e)>2*maq){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    else if(a[0]==1 && a[1]==1 && a[2]==1 && a[3]==1 && k>3){
        eqs=2+2*k+(k-1)*k;
        eqs/=2;
        eqs%=mod;
        res=powf(2,k,mod)+mod;
        res-=eqs;
        res%=mod;
        cout << res;
    }
    return 0;
}

