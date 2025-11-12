#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=1e9+7;
inline int read(){
    int v=0;
    bool f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-')f=1;
    }
    while(ch>='0'&&ch<='9'){
        v*=10;
        v+=ch-'0';
        ch=getchar();
    }
    return (f?-v:v);
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
        putchar(x%10+'0');
    }
    else putchar(x+'0');
}
struct member{
    int a,b,c;
    int A,B,C;
}m[N];
int cnt[4];
int ans=0;
bool asd(member x,member y){
    int k1=x.c-x.a+x.b-x.a,k2=y.c-y.a+y.b-y.a;
    return abs(k1)<abs(k2);
}
bool qwe(member x,member y){
    return x.a>y.a;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    bool broismdfktired=1;
    while(T--){
        ans=cnt[1]=cnt[2]=cnt[3]=0;
        int n=read();
        for(int i=1;i<=n;i++){
            int a[4]={0,read(),read(),read()};
            if(a[2]^a[3]||a[2])broismdfktired=0;
            m[i]={a[1],a[2],a[3]};
            int res=0,ip=0;
            for(int j=1;j<=3;j++){
                if(a[j]>res){
                    m[i].A=j;
                    res=a[j];
                    ip=j;
                }
            }
            cnt[ip]++;
        }
        if(broismdfktired){
            sort(m+1,m+n+1,qwe);
            for(int i=1;(i<<1)<=n;i++){
                ans+=m[i].a;
            }
            write(ans);
            puts("");
            continue;
        }
        sort(m+1,m+n+1,asd);
        int f=0;
        for(int i=1;i<=3;i++)if((cnt[i]<<1)>n)f=i;
        for(int i=1;i<=n;i++){
            if((cnt[f]<<1)<=n)break;
            if(m[i].A==f){
                if(f==1){
                    if(m[i].b>m[i].c)m[i].A=2;
                    else m[i].A=3;
                }
                else if(f==2){
                    if(m[i].a>m[i].c)m[i].A=1;
                    else m[i].A=3;
                }
                else{
                    if(m[i].a>m[i].b)m[i].A=1;
                    else m[i].A=2;
                }
                cnt[f]--;
            }
        }
        for(int i=1;i<=n;i++)
            ans+=(m[i].A==1?m[i].a:(m[i].A==2?m[i].b:m[i].c));
        write(ans);
        puts("");
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

byd ex
*/