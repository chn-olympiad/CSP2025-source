#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][4],fi[N],se[N],cnt[4],subb[N];

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}

inline void write(int x){
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

inline void sol(){
    int n=read();
    memset(cnt,0,sizeof cnt);
    memset(fi,0,sizeof fi);
    memset(se,0,sizeof se);
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++) a[i][j]=read();
        for(int j=1;j<=3;j++){
            if(a[i][j]>a[i][fi[i]]) se[i]=fi[i],fi[i]=j;
            else if(a[i][j]>a[i][se[i]]) se[i]=j; 
        }
        // subb[i]=a[i][fi[i]]-a[i][se[i]];
        cnt[fi[i]]++;
        sum+=a[i][fi[i]];
    }
    // for(int i=1;i<=n;i++) cout<<fi[i]<<" "<<se[i]<<endl;
    // sort(subb+1,subb+n+1);
    int flag=0;
    for(int i=1;i<=3;i++){
        if(cnt[i]>n/2){
            flag=i;
        }
    }
    int idx=0;
    for(int i=1;i<=n;i++){
        if(fi[i]==flag){
            subb[++idx]=a[i][fi[i]]-a[i][se[i]];
        }
    }
    sort(subb+1,subb+idx+1);
    // cout<<flag<<endl;
    // cout<<cnt[flag]<<endl;
    if(!flag){
        printf("%lld\n",sum);
        return ;
    }
    else{
        // cout<<"!!!";
        int now=cnt[flag]-n/2;
        for(int i=1;i<=now;i++){
            sum-=subb[i];
        }
        printf("%lld\n",sum);
        return;
    }
    
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        sol();
    }

    return 0;
}