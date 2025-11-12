#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int T,n;
struct node{int b[4],id[4];bool del;}a[100001];
namespace Subtask1{
    bool used[100];
    int ans=0;
    int c[4];
    inline void dfs(int step,int now){
        if(step==n+1){
            //cout<<ans<<endl;
            ans=max(ans,now);
            return;
        }
        for(int i=1;i<=3;i++){
            if(c[i]<n/2){
                c[i]++;
                dfs(step+1,now+a[step].b[i]);
                c[i]--;
            }
        }
    }
    inline void main(){
        memset(used,false,sizeof(used));
        c[1]=c[2]=c[3]=0;
        ans=0;
        dfs(1,0);
        write(ans);
        putchar('\n');
    }
}
inline bool cmp(node x,node y){return x.b[1]>y.b[1];}
namespace Subtask2{
    inline void main(){
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++)ans+=a[i].b[1];
        write(ans);
        putchar('\n');
    }
}
int c[100001],len=0;
int d[4];
int p[4];
inline bool cmp1(node x,node y){return x.b[p[1]]>y.b[p[1]];}
inline bool cmp2(node x,node y){return x.b[p[2]]>y.b[p[2]];}
inline bool cmp3(node x,node y){return x.b[p[3]]>y.b[p[3]];}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        p[1]=1;p[2]=2;p[3]=3;
        n=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                a[i].b[j]=read();
            }
        }
        for(int i=1;i<=n;i++){
            int mx=-1,mxid=0;
            for(int j=1;j<=3;j++){
                if(a[i].b[j]>mx){
                    mx=a[i].b[j];
                    mxid=j;
                }
            }
            a[i].id[mxid]=1;
            int mx2=0,mxid2=0;
            for(int j=1;j<=3;j++){
                if(j==mxid)continue;
                if(a[i].b[j]>mx2){
                    mx2=a[i].b[j];
                    mxid2=j;
                }
            }
            a[i].id[mxid2]=2;
            for(int j=1;j<=3;j++){
                if(j==mxid||j==mxid2)continue;
                a[i].id[j]=3;
            }
        }
        if(n<=10){
            Subtask1::main();
            continue;
        }
        bool sub2=true;
        for(int i=1;i<=n;i++){
            if(!(a[i].b[2]==0&&a[i].b[3]==0)){
                sub2=false;
                break;
            }
        }
        if(sub2){
            Subtask2::main();
            continue;
        }
        int ans=0;
        do{
            d[1]=d[2]=d[3]=0;
            for(int i=1;i<=n;i++)a[i].del=false;
            int tmp=0;
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n;i++){
                if(a[i].id[p[1]]==1&&d[p[1]]<n/2){
                    tmp+=a[i].b[p[1]];
                    d[p[1]]++;
                    a[i].del=true;
                }
            }
            sort(a+1,a+n+1,cmp2);
            for(int i=1;i<=n;i++){
                if(a[i].del)continue;
                if(a[i].id[p[2]]==1&&d[p[2]]<n/2){
                    tmp+=a[i].b[p[2]];
                    d[p[2]]++;
                    a[i].del=true;
                }
            }
            sort(a+1,a+n+1,cmp3);
            for(int i=1;i<=n;i++){
                if(a[i].del)continue;
                if(d[p[3]]<n/2){
                    tmp+=a[i].b[p[3]];
                    a[i].del=true;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i].del)continue;
                for(int j=1;j<=3;j++){
                    if(d[j]<n/2){
                        d[j]++;
                        tmp+=a[i].b[j];
                    }
                }
            }
            ans=max(ans,tmp);
        }while(next_permutation(p+1,p+3+1));
        write(ans);
        putchar('\n');
    }

    return 0;
}
