#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll x=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return f*x;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
const int N=5e5+5;
int n,a[N],s[N],t[N],k;
map<int,int>b;
struct section{
    int l,r;
};
vector<section>sec;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        s[i]=a[i]^s[i-1];
        t[i]=s[i]^k;
        b[t[i]]=i;
        if(b.find(s[i])!=b.end()){
            sec.push_back((section){b[s[i]]+1,i});
        }
        if(t[i]==0){
            sec.push_back((section){1,i});
        }
    }
    sort(sec.begin(),sec.end(),[](section x,section y){return x.r<y.r;});
    int ans=0,lst=0;
    for(section i:sec){
        if(i.l>i.r){
            continue;
        }
        if(i.l>lst){
            lst=i.r;
            ++ans;
        }
    }
    print(ans);
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

