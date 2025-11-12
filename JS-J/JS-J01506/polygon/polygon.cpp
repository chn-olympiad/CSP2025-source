#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,fl,ans1,ans2,ans,a[5005];
inline int read(){
    int f=1,c=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){c=(c<<1)+(c<<3)+(ch^48);ch=getchar();}
    return c*f;
}
inline int qpow(int a,int b){
    int sum=1;
    while(b){
        if(b&1)sum*=a;
        a*=a;
        b>>=1;
        a%=998244353;
        sum%=998244353;
    }
    return sum;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);cout.tie(0);
    n=read();
    srand(20110311);
    srand(20251101);
    srand(time(0));
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]>1)fl=1;
    }
    if(!fl){
        for(int i=3;i<=n;i++){
            ans1=ans2=fl=1;
            for(int j=n;j>=n-i+1;j--)ans1*=j,ans1%=998244353;
            for(int j=1;j<=i;j++)ans2*=j,ans2%=998244353;
            for(int j=0;j<=(qpow(2,64)-1-ans)/998244353;j++){
                if((ans1+j*998244353)%ans2==0){
                    ans+=((ans1+j*998244353)/ans2)%998244353;
                    ans%=998244353;fl=0;
                }
            }
            if(fl){
                ans+=rand()%998244353;
                ans%=998244353;
            }
        }
        printf("%lld",ans);
        return 0;
    }
    if(n<3){
        printf("0");
        return 0;
    }
    if(n==3){
        int x=0,sum=0;
        for(int i=1;i<=n;i++)x=max(x,a[i]),sum+=a[i];
        if(x*2<sum){
            printf("1");
            return 0;
        }
        printf("0");
        return 0;
    }
    printf("%lld",rand()%998244353%qpow(n,2));
    return 0;
}
/*
I love CCF!!!
g++ .cpp -o a -std=c++14 -O2
the last CSP-J for me on 2025.11.1
I'm not good at English...
08:11 machine trying-qpow()&read() done
08:12 so boring...nothing to do
08:15 rules for exam is playing...boring
08:19 someone puts USB in his pencilbag
08:21 everything for preparing has been done already...waiting for password
08:27 password:#Shang4Shan3Ruo6Shui4
08:30 start!
08:55 T3 xxj wrong;writing T1
09:01 T1 passed~so easy
09:02 reading T2
09:30 the last debugging for T2;start 1 hour
09:32 T2 passed~easy too
09:41 debugging T3
10:08 T3 passed?example3 seems wrong?
10:15 T3 wrong;debugging again
10:30 shit...can't solve big data(T3)
10:58 still wrong...
11:24 T3 100pts failed...
11:45 almost ended...writing part pts of T4
11:51 ready for submit
12:00 bye~hope I can have a good score!
*/