#include<bits/stdc++.h>
#define N 110
using namespace std;
int n,m,a[N];
int d[3][2]={1,0,0,1,-1,0};
inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*y;
}
inline void write(int x){
    if(!x) putchar('0');
    char F[200];
    if(x<0) putchar('-'),x=-x;
    int tmp=x,cnt=0;
    while(tmp>0){
        F[++cnt]=tmp%10+'0';
        tmp/=10;
    }
    while(cnt>0) putchar(F[cnt]),cnt--;
}
bool cmp(int l1,int l2){
    return l1>=l2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n*m;i++){
        a[i]=read();
    }
    int x=a[1],cnt=1,c=1,r=1,k=0;
    sort(a+1,a+n*m+1,cmp);
    while(a[cnt]!=x){
        c+=d[k][0];
        r+=d[k][1];
        if(k==1){
            if(c==n) k=2;
            else k=0;
        }
        else if((c==n||c==1)) k=1;
        cnt++;
    }
    write(r);
    cout<<" ";
    write(c);
    return 0;
}
