#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
char s[100000];
int c[100000];
int cnt=0;
int qp(int x,int k){
    int z=x,res=1;
    while(k){
        if(k&1)  res=res*z%mod;
        k>>=1;z=z*z%mod;
    }
    return res;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    if(m==n)  cnt=2;
    for(int i=1;i<=n;i++){
        if(cnt==2&&s[i]=='0')  cnt=1;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&c[i]);
        if(cnt==2&&c[i]==0)  cnt=1;
    }
    if(cnt==1)  printf("0");
    else if(cnt==2)  printf("%d\n",qp(2,n));
    else  printf("0");
}