#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
const int N=505;
int n,m,c[N];
char dfct[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int one=0,die=0;
    scanf("%d%d%s",&n,&m,dfct+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]),one+=dfct[i]-'0',die+=(c[i]==0);
    if(one<m||n-die<m) putchar('0'),exit(0);
    if(n==m){
        ll ans=1;
        for(int i=2;i<=n;i++) ans=ans*i%P;
        printf("%lld\n",ans),exit(0);
    }
    if(n<=10){
        int tmp[15]={},ans=0,got;
        for(int i=1;i<=n;i++) tmp[i]=i;
        do{
            die=got=0;
            for(int i=1;i<=n;i++){
                if(die>=c[tmp[i]]) ++die;
                else if(dfct[i]=='0') ++die;
                else ++got;
            }
            if(got>=m) ++ans;
        }while(next_permutation(tmp+1,tmp+n+1));
        printf("%d",ans),exit(0);
    }
    printf("0");
    return 0;
}
//g++ -Wall -std=c++14 -O2 -fsanitize=address,undefined employ.cpp -o employ;./employ