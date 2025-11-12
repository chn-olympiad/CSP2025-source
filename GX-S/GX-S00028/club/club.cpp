/*
2
10 9 8
4 0 0

i:1~n

int x1=((people1<=n/2)?dp[now-1][1]+c[1]:max(dp[now-1][1],c[1]));
int y1=max(dp[now-1][2]+c[1],dp[now-1][3]+c[1]);
if(x1>y1){
    ++people1,dp[now][1]=x1;
}
else dp[now][1]=y1;

int x2=((people2<=n/2)?dp[now-1][2]+c[2]:max(dp[now-1][2],c[2]));
int y2=max(dp[now-1][1]+c[1],dp[now-1][3]+c[3]);
if(x2>y2){
    ++people2,dp[now][1]=x2;
}
else dp[now][1]=y2;

int x3=((people3<=n/2)?dp[now-1][3]+c[3]:max(dp[now-1][3],c[3]));
int y3=max(dp[now-1][2]+c[2],dp[now-1][1]+c[1]);
if(x3>y3){
    ++people3,dp[now][3]=x3;
}
else dp[now][3]=y3;





*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int INF=1e9;
int t,n,ans=0,people1,people2,people3,dp[N][4],idx1=0,idx2=0,idx3=0;
int heap1[4*N],heap2[4*N],heap3[4*N];
struct haha{
    int f,s,t;
}c[N];
void put1(int x){
    heap1[++idx1]=x;
    int now=idx1;
    while(heap1[now/2]>x){
        swap(heap1[now/2],heap1[now]);
        now/=2;
    }
}
int pop1(){
    int res=heap1[1];
    heap1[1]=INF;
    int now=1;
    while(heap1[now]>heap1[now*2]||heap1[now]>heap1[now*2+1]){
        if(heap1[now*2]<heap1[now*2+1])swap(heap1[now*2],heap1[now]);
        else swap(heap1[now*2+1],heap1[now]);
    }
    return res;
}
void put2(int x){
    heap2[++idx2]=x;
    int now=idx2;
    while(heap2[now/2]>x){
        swap(heap2[now/2],heap2[now]);
        now/=2;
    }
}
int pop2(){
    int res=heap2[1];
    heap2[1]=INF;
    int now=1;
    while(heap2[now]>heap2[now*2]||heap2[now]>heap2[now*2+1]){
        if(heap2[now*2]<heap2[now*2+1])swap(heap2[now*2],heap2[now]);
        else swap(heap2[now*2+1],heap2[now]);
    }
    return res;
}
void put3(int x){
    heap3[++idx3]=x;
    int now=idx3;
    while(heap3[now/2]>x){
        swap(heap3[now/2],heap3[now]);
        now/=2;
    }
}
int pop3(){
    int res=heap3[1];
    heap3[1]=INF;
    int now=1;
    while(heap3[now]>heap3[now*2]||heap3[now]>heap3[now*2+1]){
        if(heap3[now*2]<heap3[now*2+1])swap(heap3[now*2],heap3[now]);
        else swap(heap3[now*2+1],heap3[now]);
    }
    return res;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        idx1=idx2=idx3=0,ans=0,people1=1,people2=1,people3=1;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>c[i].f>>c[i].s>>c[i].t;
            dp[i][1]=0,dp[i][2]=0,dp[i][3]=0;
        }
        for(int i=0;i<=2*n+1;++i)heap1[i]=heap2[i]=heap3[i]=INF;
        dp[1][1]=c[1].f,dp[1][2]=c[1].s,dp[1][3]=c[1].t;
        //cout<<"dp[1][2]="<<dp[1][2]<<'\n';
        put1(c[1].f);put2(c[1].s);put3(c[1].t);
        for(int now=2;now<=n;++now){
            int y_1=max(dp[now-1][2],dp[now-1][3])+c[now].f;
            if(people1<n/2){
                int x1=dp[now-1][1]+c[now].f;
                if(x1<dp[now-1][1]-heap1[1]+c[now].f){
                    if(y_1<dp[now-1][1]-heap1[1]+c[now].f){
                        dp[now][1]=dp[now-1][1]-heap1[1]+c[now].f;
                        pop1();
                        put1(c[now].f);
                    }
                    else{
                        dp[now][1]=y_1;
                    }
                }
                else if(x1<y_1){
                    dp[now][1]=y_1;
                }
                else dp[now][1]=x1,++people1;
            }
            else{
                int x1=dp[now-1][1];
                if(x1<dp[now-1][1]-heap1[1]+c[now].f){
                    if(y_1<dp[now-1][1]-heap1[1]+c[now].f){
                        dp[now][1]=dp[now-1][1]-heap1[1]+c[now].f;
                        pop1();
                        put1(c[now].f);
                    }
                    else{
                        dp[now][1]=y_1;
                    }
                }
                else if(x1<y_1){
                    dp[now][1]=y_1;
                }
                else dp[now][1]=x1;
            }


            int y_2=max(dp[now-1][1],dp[now-1][3])+c[now].s;
            if(people2<n/2){
                int x2=dp[now-1][2]+c[now].s;
                if(x2<dp[now-1][2]-heap2[1]+c[now].s){
                    if(y_2<dp[now-1][2]-heap2[1]+c[now].s){
                        dp[now][2]=dp[now-1][2]-heap2[1]+c[now].s;
                        pop2();
                        put2(c[now].s);
                    }
                    else{
                        dp[now][2]=y_2;
                    }
                }
                else if(x2<y_2){
                    dp[now][2]=y_2;
                }
                else dp[now][2]=x2,++people2;
            }
            else{
                int x2=dp[now-1][2];
                if(x2<dp[now-1][2]-heap2[1]+c[now].s){
                    if(y_2<dp[now-1][2]-heap2[1]+c[now].s){
                        dp[now][2]=dp[now-1][2]-heap2[1]+c[now].s;
                        pop2();
                        put2(c[now].s);
                    }
                    else{
                        dp[now][2]=y_2;
                    }
                }
                else if(x2<y_2){
                    dp[now][2]=y_2;
                }
                else dp[now][2]=x2;
            }
            int y_3=max(dp[now-1][1],dp[now-1][2])+c[now].t;
            if(people3<n/2){
                int x3=dp[now-1][3]+c[now].t;
                if(x3<dp[now-1][3]-heap3[1]+c[now].t){
                    if(y_3<dp[now-1][3]-heap3[1]+c[now].t){
                        dp[now][3]=dp[now-1][3]-heap3[1]+c[now].t;
                        pop3();
                        put3(c[now].t);
                    }
                    else{
                        dp[now][3]=y_3;
                    }
                }
                else if(x3<y_3){
                    dp[now][3]=y_3;
                }
                else dp[now][3]=x3,++people3;
            }
            else{
                int x3=dp[now-1][3];
                if(x3<dp[now-1][3]-heap3[1]+c[now].t){
                    if(y_3<dp[now-1][3]-heap3[1]+c[now].t){
                        dp[now][3]=dp[now-1][3]-heap3[1]+c[now].t;
                        pop3();
                        put3(c[now].t);
                    }
                    else{
                        dp[now][3]=y_3;
                    }
                }
                else if(x3<y_3){
                    dp[now][3]=y_3;
                }
                else dp[now][3]=x3;
            }
        }
        ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
        cout<<ans<<'\n';
    }
    return 0;
}
