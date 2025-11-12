#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans=0;
int n,t;
struct ST{
    int a1,a2,a3;
}a[N];
bool cmp(ST a,ST b){

    return a.a1>b.a1;
}
struct node{
    int num;
    int k;
}c[N];
bool cmpp(node aa,node bb){
    return aa.k<bb.k;
}
void dfs(int i,int sum,int x,int y,int z){
    if(x>t||y>t||z>t) return;
    if(i>n){
        ans=max(ans,sum);
        return;
    }
    dfs(i+1,sum+a[i].a1,x+1,y,z);
    dfs(i+1,sum+a[i].a2,x,y+1,z);
    dfs(i+1,sum+a[i].a3,x,y,z+1);
}
int find(){
    int x=0,y=0;
    int ss=0;
    for(int i=1;i<=n;i++){
        c[i].k=max(a[i].a1,a[i].a2)-min(a[i].a1,a[i].a2);
        c[i].num=i;
        if(a[i].a1>a[i].a2) x++,ss+=a[i].a1;
        if(a[i].a1<a[i].a2) y++,ss+=a[i].a2;
        if(a[i].a1==a[i].a2) ss+=a[i].a1;
    }
    if(x<=t&&y<=t) return ss;
    sort(c+1,c+n+1,cmpp);
    if(x>t){
        for(int i=1;i<=n;i++){
            if(x<=t) return ss;
            int q=c[i].num;
            if(a[q].a1>a[q].a2){
                ss-=c[i].k;
                x--,y++;
            }
        }
        return ss;
    }
    if(y>t){
        for(int i=1;i<=n;i++){
            if(y<=t) return ss;
            int q=c[i].num;
            if(a[q].a1<a[q].a2){
                ss-=c[i].k;
                x++,y--;
            }
        }
        return ss;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n;
        t=n/2;
        int xx=1,yy=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            //cout<<a[i].a1<<a[i].a2<<a[i].a3<<endl;
            if(a[i].a2!=0) xx=0;
            if(a[i].a3!=0) yy=0;
        }
        if(xx==1&&yy==1){
            sort(a+1,a+n+1,cmp);
            int s=0;
            for(int i=1;i<=t;i++){
                s+=a[i].a1;
            }
            cout<<s<<endl;
            continue;
        }
        if(yy==1){
            cout<<find()<<endl;
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
