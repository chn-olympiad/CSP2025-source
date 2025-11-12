#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll ans=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        ans=(ans<<1)+(ans<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return ans*f;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x+'0');
    }else{
        print(x/10);
        putchar(x%10+'0');
    }
}
const int M=998244353;
int n,m;
bool a[505],vis[505];
int c[505];
ll ans;
void dfs(int t,int ct){
    if(ct+m>n){
        return;
    }
    if(t>n){
        if(ct+m<=n){
            ++ans;
            ans%=M;
        }
        return;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]&&c[i]>ct){
            vis[i]=1;
            dfs(t+1,ct+1-a[t]);
            vis[i]=0;
        }
    }
}
bool flaga=1;
int sum;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i]=getchar()^'0';
        flaga&=a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;++i){
        c[i]=read();
    }
    if(sum<m){
        print(0);
        return 0;
    }
    if(m==1){
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(i==1){
                break;
            }
            ++cnt;
        }
        for(int i=1;i<=n;++i){
            if(c[i]>cnt){
                ++ans;
            }
        }
        for(int i=1;i<n;++i){
            ans*=i;
            ans%=M;
        }
    }else if(m==n){
        if(flaga){
           bool flag=1;
           for(int i=1;i<=n;++i){
                if(c[i]==0){
                    flag=0;
                    break;
                }
           }
           if(flag){
                ans=1;
                for(int i=1;i<=n;++i){
                    ans*=i;
                    ans%=m;
                }
           }
        }
    }else{
        dfs(1,0);
    }
    print(ans);
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
