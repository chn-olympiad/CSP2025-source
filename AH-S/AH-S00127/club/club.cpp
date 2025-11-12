#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100007
using namespace std;
struct node{
    long long a,b,c;
} g[N];
int t;
long long n;
long long f[N][7];
long long c1,c2,c3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while( t-- ){
        memset(f,0,sizeof(f));
        c1=c2=c3=0;
        scanf("%d",&n);
        long long tmp=n/2;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].c);
        }
        f[1][1]=g[1].a;
        f[1][2]=g[1].b;
        f[1][3]=g[1].c;
//        if( g[1].a>g[1].b && g[1].a>g[1].c ) c1++;
//        if( g[1].b>g[1].a && g[1].b>g[1].c ) c2++;
//        if( g[1].c>g[1].a && g[1].c>g[1].b ) c3++;
        for(int i=2;i<=n;i++){
            long long s=-1;
            long long p1=f[i-1][1],p2=f[i-1][2],p3=f[i-1][3];
            if( p1>p2 && p1>p3 && c1<tmp-1 ){
                s=max(s,p1);
            }
            if( p2>p1 && p2>p3 && c2<tmp-1 ){
                s=max(s,p2);
            }
            if( p3>p1 && p3>p2 && c3<tmp-1 ){
                s=max(s,p3);
            }
            if( s==-1 ){
                if( c1<tmp ){
                    s=max(s,p1);
                }
                if( c2<tmp ){
                    s=max(s,p2);
                }
                if( c3<tmp ){
                    s=max(s,p3);
                }
            }
            if( s==p1 ) c1++;
            if( s==p2 ) c2++;
            if( s==p3 ) c3++;
            f[i][1]=s+g[i].a;
            f[i][2]=s+g[i].b;
            f[i][3]=s+g[i].c;
        }
        cout<<c1<<" "<<c2<<" "<<c3<<endl;
        int answer=max(f[n][1],max(f[n][2],f[n][3]));
        cout<<answer<<endl<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
