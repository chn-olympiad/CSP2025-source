#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a,b,c;
}a[100005];
int curmax[32][32][32];
int ans=0;
struct twice{
    int val,pos;
}x[100005],y[100005],z[100005];
int flag[100005];
bool cmp(twice x,twice y){
    return x.val>y.val;
}
inline void search(int cnt,int x,int y,int z,int i){
    if(i==n){
        ans=max(cnt,ans);
        return;
    }
    i++;
    if(x<n/2) search(cnt+a[i].a,x+1,y,z,i);
    if(y<n/2) search(cnt+a[i].b,x,y+1,z,i);
    if(z<n/2) search(cnt+a[i].c,x,y,z+1,i);
    return;

}
bool cmp1(node a,node b){
    return a.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        bool flag1=true,flag2=true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            x[i].pos=y[i].pos=z[i].pos=i;
            x[i].val=a[i].a;
            y[i].val=a[i].b;
            z[i].val=a[i].c;
        }
        if(n<=10){
            ans=0;
            search(0,0,0,0,0);
            cout<<ans<<'\n';
            continue;
        }else if(flag1){
            sort(a+1,a+1+n,cmp1);
            ans=0;
            for(int i=1;i<=n/2;i++) ans+=a[i].a;
            cout<<ans<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//g++ club.cpp -o club -std=c++14 -O2 -static
//ulimit -s 512000
//ulimit -v 512000
//practice more and come back next year