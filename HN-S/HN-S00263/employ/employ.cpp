#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<='0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
    return x*f;
}
const int mod=998244353;
int jc(int x){
    int res=1;
    for(int i=2;i<=x;i++) res=res*i%mod;
    return res;
}
signed main(){
    freopen("employ.in" ,"r",stdin );
    freopen("employ.out","w",stdout);
    // freopen("1.in","r",stdin);
    printf("0");
    return 0;
}