#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct node{
    long long a,b,c;
};
node a[N];
long long dp[N][5];

bool cmp(node x,node y){
    if(x.a > y.a){
        return x.a > y.a;
    }else if(x.b > y.b){
        return x.b > y.b;
    }else{
        return x.c > y.c;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        long long n = 0;
        cin>>n;
        long long nowa[5] = {0,0,0,0};
        long long nowb[5] = {0,0,0,0};
        long long nowc[5] = {0,0,0,0};


        for(int i = 1; i <= n; i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        sort(a + 1, a + n + 1,cmp);
        for(int i = 1; i <= n; i++){
            long long na1 = nowa[1];
            long long na2 = nowa[2];
            long long na3 = nowa[3];
            long long nb1 = nowb[1];
            long long nb2 = nowb[2];
            long long nb3 = nowb[3];
            long long mx = (i + 1) / 2;
            long long ax = dp[i - 1][1];
            long long bx = dp[i - 1][2];
            long long cx = dp[i - 1][3];
            if(nowa[1] < mx && nowb[1] < mx && nowc[1] < mx){
                if(ax > bx && ax > cx){
                    nowa[1]++;
                    dp[i][1] = ax + a[i].a;
                }else if(bx > ax && bx > cx){
                    nowa[1] = nowb[1] + 1;
                    nowa[2] = nowb[2];
                    nowa[3] = nowb[3];
                    dp[i][1] = bx + a[i].a;
                }else{
                    nowa[1] = nowc[1] + 1;
                    nowa[2] = nowc[2];
                    nowa[3] = nowc[3];
                    dp[i][1] = cx + a[i].a;
                }
            }else if(nowb[1] < mx && nowc[1] < mx){
                if(bx > cx){
                    nowa[1] = nowb[1] + 1;
                    nowa[2] = nowb[2];
                    nowa[3] = nowb[3];
                    dp[i][1] = bx + a[i].a;
                }else{
                    nowa[1] = nowc[1] + 1;
                    nowa[2] = nowc[2];
                    nowa[3] = nowc[3];
                    dp[i][1] = cx + a[i].a;
                }
            }else if(nowc[1] < mx){
                nowa[1] = nowc[1] + 1;
                nowa[2] = nowc[2];
                nowa[3] = nowc[3];
                dp[i][1] = cx + a[i].a;
            }else if(nowb[1] < mx){
                nowa[1] = nowb[1] + 1;
                nowa[2] = nowb[2];
                nowa[3] = nowb[3];
                dp[i][1] = bx + a[i].a;
            }else{
                if(ax > bx && ax > cx){
                    dp[i][1] = ax;
                }else if(bx > ax && bx > cx){
                    nowa[1] = nowb[1];
                    nowa[2] = nowb[2];
                    nowa[3] = nowb[3];
                    dp[i][1] = bx;
                }else{
                    nowa[1] = nowc[1];
                    nowa[2] = nowc[2];
                    nowa[3] = nowc[3];
                    dp[i][1] = cx;
                }
            }
            if(na2 < mx && nowb[2] < mx && nowc[2] < mx){
                if(bx > ax && bx > cx){
                    nowb[2]++;
                    dp[i][2] = bx + a[i].b;
                }else if(ax > bx && ax > cx){
                    nowb[2] = na1;
                    nowb[2] = na2 + 1;
                    nowb[2] = na3;
                    dp[i][2] = ax + a[i].b;
                }else{
                    nowb[1] = nowc[1];
                    nowb[2] = nowc[2] + 1;
                    nowb[3] = nowc[3];
                    dp[i][2] = cx + a[i].b;
                }
            }else if(na2 < mx && nowc[2] < mx){
                if(ax > cx){
                    nowb[1] = na1;
                    nowb[2] = na2 + 1;
                    nowb[3] = na3;
                    dp[i][2] = ax + a[i].b;
                }else{
                    nowb[1] = nowc[1];
                    nowb[2] = nowc[2] + 1;
                    nowb[3] = nowc[3];
                    dp[i][2] = cx + a[i].b;
                }
            }else if(nowc[2] < mx){
                nowb[1] = nowc[1];
                nowb[2] = nowc[2] + 1;
                nowb[3] = nowc[3];
                dp[i][2] = cx + a[i].b;
            }else if(nowa[2] < mx){
                nowb[1] = na1;
                nowb[2] = na2 + 1;
                nowb[3] = na3;
                dp[i][2] = ax + a[i].b;
            }else{
                if(bx > ax && bx > cx){
                    dp[i][2] = bx;
                }else if(ax > bx && ax > cx){
                    nowb[1] = na1;
                    nowb[2] = na2;
                    nowb[3] = na3;
                    dp[i][2] = ax;
                }else{
                    nowb[1] = nowc[1];
                    nowb[2] = nowc[2];
                    nowb[3] = nowc[3];
                    dp[i][2] = cx;
                }
            }
            if(na3 < mx && nb3 < mx && nowc[3] < mx){
                if(cx > ax && cx > bx){
                    nowc[3]++;
                    dp[i][3] = cx + a[i].c;
                }else if(ax > bx && ax > cx){
                    nowc[3] = na1;
                    nowc[3] = na2;
                    nowc[3] = na3 + 1;
                    dp[i][3] = ax + a[i].c;
                }else{
                    nowc[1] = nb1;
                    nowc[2] = nb2;
                    nowc[3] = nb3 + 1;
                    dp[i][3] = bx + a[i].c;
                }
            }else if(na3 < mx && nb3 < mx){
                if(ax > bx){
                    nowc[1] = na1;
                    nowc[2] = na2;
                    nowc[3] = na3 + 1;
                    dp[i][3] = ax + a[i].c;
                }else{
                    nowc[1] = nb1;
                    nowc[2] = nb2;
                    nowc[3] = nb3 + 1;
                    dp[i][3] = bx + a[i].c;
                }
            }else if(nb3 < mx){
                nowc[1] = nb1;
                nowc[2] = nb2;
                nowc[3] = nb3 + 1;
                dp[i][3] = bx + a[i].c;
            }else if(na3 < mx){
                nowc[1] = na1;
                nowc[2] = na2;
                nowc[3] = na3 + 1;
                dp[i][3] = ax + a[i].c;
            }else{
                if(cx > ax && cx > bx){
                    dp[i][3] = cx;
                }else if(ax > bx && ax > cx){
                    nowc[1] = na1;
                    nowc[2] = na2;
                    nowc[3] = na3;
                    dp[i][3] = ax;
                }else{
                    nowc[1] = nb1;
                    nowc[2] = nb2;
                    nowc[3] = nb3;
                    dp[i][3] = bx;
                }
            }

        }
        cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
        for(int i = 1; i <= n; i++){
                a[i].a = 0;
                a[i].b = 0;
                a[i].c = 0;
                dp[i][1] = 0;
                dp[i][2] = 0;
                dp[i][3] = 0;
        }
        nowa[1] = 0;
        nowa[2] = 0;
        nowa[3] = 0;
        nowb[1] = 0;
        nowb[2] = 0;
        nowb[3] = 0;
        nowc[1] = 0;
        nowc[2] = 0;
        nowc[3] = 0;
    }
    return 0;
}

