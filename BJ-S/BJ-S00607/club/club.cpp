#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node{
    int a1,a2,a3;
}a[N];
int cnta,cntb,cntc;
int maxx=-1,n;
void dfs(int d,int num){
    if(d > n){
        maxx = max(maxx,num);
        return;
    }
    if(cnta <= n/2){
        cnta ++;
        dfs(d+1,num + a[d].a1);
        cnta --;
    }
    if(cntb <= n/2){
        cntb ++;
        dfs(d+1,num + a[d].a2);
        cntb --;
    }
    if(cntc <= n/2){
        cntc ++;
        dfs(d+1,num + a[d].a3);
        cntc --;

    }
}
void dfs1(int d,int num){
    if(d > n ||(cnta > n/2 && cntb >n/2)){
        maxx = max(maxx,num);
        return;
    }
    if(cnta <= n/2){
        cnta ++;
        dfs(d+1,num + a[d].a1);
        cnta --;
    }
    if(cntb <= n/2){
        cntb ++;
        dfs(d+1,num + a[d].a2);
        cntb --;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int A=1,B=1;
        priority_queue<int> aq;
        memset(a,0,sizeof(a));
        cnta=0;cntb=0;cntc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            if(a[i].a2 != 0 || a[i].a3 != 0) A = 0;
            aq.push(a[i].a1);
            if(a[i].a3 != 0) B=0;
        }
        if(A){
            int cnt=0;
            for(int i=1;i<=n/2;i++){
                cnt += aq.top();
                aq.pop();
            }
            cout<<cnt<<"\n";
            continue;
        }
        if(B){
            dfs1(1,0);
            cout<<maxx<<"\n";
            continue;
        }
        dfs(1,0);
        cout<<maxx<<"\n";
        maxx=0;
    }
    return 0;
}
