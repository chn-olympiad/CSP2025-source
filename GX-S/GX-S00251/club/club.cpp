#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int t,n,res,cnt,t1,t2,t3,in1[N],in2[N],in3[N],d[N][5],a[N][5];
bool cmp1(int id1,int id2) {return d[id1][1]<d[id2][1];}
bool cmp2(int id1,int id2) {return d[id1][2]<d[id2][2];}
bool cmp3(int id1,int id2) {return d[id1][3]<d[id2][3];}
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0' or ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0' and ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--) {
        n=read();res=0;
        t1=0;t2=0;t3=0;
        for(int i=1; i<=n; i++) {
            a[i][1]=read();
            a[i][2]=read();
            a[i][3]=read();
            d[i][1]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
            d[i][2]=max(a[i][3]-a[i][2],a[i][1]-a[i][2]);
            d[i][3]=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
            int mx=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]==mx) {res+=a[i][1];in1[++t1]=i;}
            else if(a[i][2]==mx) {res+=a[i][2];in2[++t2]=i;}
            else if(a[i][3]==mx) {res+=a[i][3];in3[++t3]=i;}
        }
        if(t1>n/2) {
            sort(in1+1,in1+1+t1,cmp1);
            for(int i=n/2+1; i<=t1; i++) {
                res+=d[in1[i]][1];
            }
        }
        if(t2>n/2) {
            sort(in2+1,in2+1+t2,cmp2);
            for(int i=n/2+1; i<=t2; i++) {
                res+=d[in2[i]][2];
            }
        }
        if(t3>n/2) {
            sort(in3+1,in3+1+t3,cmp3);
            for(int i=n/2+1; i<=t3; i++) {
                res+=d[in3[i]][3];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
