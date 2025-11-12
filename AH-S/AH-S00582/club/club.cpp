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
    return f*ans;
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
const int N=1e5+5;
int n;
struct stu{
    int a[5],mx,sc;
    bool operator<(const stu&b)const{
        return mx-sc<b.mx-b.sc;
    }
}v[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    do{
        n=read();
        ll ans=0;
        for(int i=1;i<=n;++i){
            v[i].a[1]=read();
            v[i].a[2]=read();
            v[i].a[3]=read();
            v[i].mx=max(v[i].a[1],max(v[i].a[2],v[i].a[3]));
            v[i].sc=v[i].a[1]+v[i].a[2]+v[i].a[3]-v[i].mx-min(v[i].a[1],min(v[i].a[2],v[i].a[3]));
        }
        sort(v+1,v+n+1);
        reverse(v+1,v+n+1);
        int cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;++i){
            if(v[i].mx==v[i].a[1]){
                if(cnta*2==n){
                    ans+=v[i].sc;
                    if(v[i].sc==v[i].a[2]){
                        ++cntb;
                    }else{
                        ++cntc;
                    }
                }else{
                    ++cnta;
                    ans+=v[i].mx;
                }
            }else if(v[i].mx==v[i].a[2]){
                if(cntb*2==n){
                    ans+=v[i].sc;
                    if(v[i].sc==v[i].a[1]){
                        ++cnta;
                    }else{
                        ++cntc;
                    }
                }else{
                    ++cntb;
                    ans+=v[i].mx;
                }
            }else{
                if(cntc*2==n){
                    ans+=v[i].sc;
                    if(v[i].sc==v[i].a[2]){
                        ++cntb;
                    }else{
                        ++cnta;
                    }
                }else{
                    ++cntc;
                    ans+=v[i].mx;
                }
            }
        }
        print(ans);
        el;
    }while(--T);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
