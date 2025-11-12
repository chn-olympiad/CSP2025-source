#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    int x,y,z;
    int secmx,firmx;
} a[3][N];
bool cmp(node x,node y){
    return x.firmx-x.secmx<y.firmx-y.secmx;
}
inline int read(){
    int f=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9'){
        f=f*10+c-48;
        c=getchar();
    }
    return f;
}
int cur[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Q=read();
    //cout<<1<<'\n';
    while (Q--){
        //memset(a,0,sizeof a);
        int n=read();
        int sum=0;
        cur[1]=0;
        cur[2]=0;
        cur[3]=0;
        for (int i=1;i<=n;i++){
            int x=read(),y=read(),z=read();
            int mx=max(x,max(y,z));
            int secmx;
            if (mx==x) secmx=max(y,z);
            else if (mx==y) secmx=max(x,z);
            else secmx=max(x,y);
            sum+=mx;
            if (mx==x){
                a[1][++cur[1]]={x,y,z,secmx,mx};
            }
            else if (mx==y){
                a[2][++cur[2]]={x,y,z,secmx,mx};
            }
            else{
                a[3][++cur[3]]={x,y,z,secmx,mx};
            }
        }
        int op=-1;
        for (int i=1;i<=3;i++){
            if (cur[i]>n/2){
                op=i;
                break;
            }
        }
        if (op==-1) cout<<sum<<'\n';
        else{
            sort(a[op]+1,a[op]+cur[op]+1,cmp);
            for (int i=1;i<=cur[op]-n/2;i++){
                sum+=a[op][i].secmx-a[op][i].firmx;
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}
