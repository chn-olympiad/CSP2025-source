#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,c[506],leaving=0,zero=0;
char s[506];
bool flag = true;
int minc=0x7f7f7f7f,maxc=-1;

ll calc(ll n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans%=998244353;
        ans*=i;
        ans%=998244353;
    }
    return ans;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
        if(c[i]==0)leaving++;
        else {
            if(c[i]<minc)minc=c[i];
            if(c[i]>maxc)maxc=c[i];
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!='1'){
                flag = false;
                zero++;
        }
    }
    if(flag){
        if(n-leaving>=m){
            int tmp = n-leaving-m;
            if(tmp==0)printf("%lld",calc(n-leaving)*calc(leaving));
            else{
                ll ans = calc(n-leaving);
                ans += calc(calc(leaving-minc)*leaving)*(n-leaving+1);
                printf("%lld",ans);
            }
        }
        else{
            printf("0");
        }
    }
    else if(m==1){
            long long ans = calc(n);
            ans-= calc(n-1)*zero;
            printf("%lld",ans);
    }
    return 0;
}

