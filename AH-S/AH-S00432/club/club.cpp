#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x*=10,x+=(int)(ch-'0');
        ch=getchar();
    }
    return x*f;
}

const int N=100005;
int n,used[4];
struct node{
    int a[4];
    int tag,delta;
}a[N];

bool cmp(node A,node B){
    return A.delta<B.delta;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        long long ans=0;
        used[1]=used[2]=used[3]=0;
        for(int i=1;i<=n;i++){
            a[i].a[1]=read(),a[i].a[2]=read(),a[i].a[3]=read();
            if(a[i].a[1]>=a[i].a[2] && a[i].a[1]>=a[i].a[3]) {
                a[i].tag=1;
                if(a[i].a[2]>=a[i].a[3]) a[i].delta=a[i].a[1]-a[i].a[2];
                else a[i].delta=a[i].a[1]-a[i].a[3];
            }
            else if(a[i].a[2]>=a[i].a[1] && a[i].a[2]>=a[i].a[3]) {
                a[i].tag=2;
                if(a[i].a[1]>=a[i].a[3]) a[i].delta=a[i].a[2]-a[i].a[1];
                else a[i].delta=a[i].a[2]-a[i].a[3];
            }
            else {
                a[i].tag=3;
                if(a[i].a[1]>=a[i].a[2]) a[i].delta=a[i].a[3]-a[i].a[1];
                else a[i].delta=a[i].a[3]-a[i].a[2];
            }
            used[a[i].tag]++;
            ans+=a[i].a[a[i].tag];
        }
        int maxn=n/2,maxtag;
        sort(a+1,a+n+1,cmp);
        if(used[1]<=maxn&&used[2]<=maxn&&used[3]<=maxn){
            cout<<ans<<endl;
            continue;
        }
        if(used[1]>maxn) maxtag=1;
        if(used[2]>maxn) maxtag=2;
        if(used[3]>maxn) maxtag=3;
        for(int i=1;i<=n && used[maxtag]>maxn;i++){
            if(a[i].tag!=maxtag) continue;
            else ans-=a[i].delta,used[maxtag]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}   
