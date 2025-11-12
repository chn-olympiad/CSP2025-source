#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5010;
const int mod=998244353;

int a[maxn];
int two_pre[maxn];//tow_pre[i]=a[i]+a[i+1]
int n;
int ans;

int fact(int x){
    if(x==0) return 1;
    int pi=1;
    for(int i=2;i<=x;i++){
        pi*=i;
    }
    return pi;
}

int C(int x,int y){
    return fact(x)/(fact(y)*fact(x-y));
}

int mtd(int lft,int rgt){
    int idx;
    for(int i=lft;i<=rgt-2;i++){
        if(two_pre[i]>a[rgt]){
            idx=i;
            break;
        }
    }

    int len=rgt-idx+1;
    //sum( C(len,i) )
    int sum=0;
    for(int i=2;i<=len;i++){
        sum+=C(len,i);
    }

    return sum-lft-(n-rgt)+1;
}

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //input
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //spj1
    bool is1=true;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            is1=false;
            break;
        }
    }
    if(is1){
        int ANS=0;
        for(int i=3;i<=n;i++){
            ANS+=C(n,i);
        }
        cout<<ANS;
        return 0;
    }
    //spj2
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3] and a[1]+a[3]>a[2] and a[2]+a[3]>a[1]){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }

    //n>3
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        two_pre[i]=a[i]+a[i+1];
    }

    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            ans+=mtd(i,j)%mod;
        }
    }
    cout<<ans;
    return 0;
}
