#include<bits/stdc++.h>
#define N 100000
#define M 3
#define K 0
#define INF 0
#define mod 0
#define int1 long long
using namespace std;
int1 n,i,a[N + 5][M + 5],ans,s,ppp;
int1 ccc;
int1 pi[N + 5],c[N + 5];
const int1 read(){
    int1 x = 0;
    bool f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        f ^= (ch == '-');
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return (f ? x : -x);
}
const bool ischar(const char ch,const int1 x){
    return (((x & 1) && ch >= 'A' && ch <= 'Z') || ((x & 2) && ch >= 'a' && ch <= 'z') || 
    ((x & 4) && ch >= '0' && ch <= '9') || 
    ((x & 8) && ch != ' ' && ch != '\r' && ch != '\n') || ((x & 16) && ch != '\r' && ch != '\n'));
}
const char getc(const int1 x){
    char ch = getchar();
    while(!ischar(ch,x)){
        ch = getchar();
    }
    return ch;
}
const int1 getst(char a[],int1 st,const int1 x){
    char ch = getchar();
    while(!ischar(ch,x)){
        ch = getchar();
    }
    st--;
    while(ischar(ch,x)){
        a[++st] = ch;
        ch = getchar();
    }
    return st;
}
void uprint(const int1 x){
    if(x >= 10){
        uprint(x / 10);
    }
    putchar(x % 10 ^ 48);
    return ;
}
void print(const int1 x){
    if(x < 0){
        putchar('-');
        return uprint(-x);
    }
    return uprint(x);
}
void ps(const int1 x){
    uprint(x);
    putchar(' ');
    return ;
}
void pe(const int1 x){
    uprint(x);
    putchar('\n');
    return ;
}
bool cmp(int1 x,int1 y){
    return c[x] > c[y];
}
void solve(){
    n = read();
    ans = 0;
    ppp = 0;
    s = 0;
    for(i = 1; i <= n; i++){
        a[i][1] = read(),a[i][2] = read(),a[i][3] = read();
        pi[i] = i,c[i] = a[i][1] - max(a[i][2],a[i][3]);
        ppp += a[i][1];
    }
    sort(pi + 1,pi + n + 1,cmp);
    const int1 lim = n >> 1;
    priority_queue<int1,vector<int1>,greater<int1> > q;
    priority_queue<int1> bzd;
    ccc = 0;
    for(i = n; i > lim + 1; i--){
        const int1 x = pi[i];
        s += a[x][3];
        ppp -= a[x][1];
        q.push(a[x][2] - a[x][3]);
        ccc++;
        s += a[x][2] - a[x][3];
        while(ccc > lim || (ccc > 0 && ccc > n - i + 1 - lim && q.top() < 0)){
            bzd.push(q.top());
            s -= q.top();
            ccc--;
            q.pop();
        }
        while(!bzd.empty() && (ccc < n - i + 1 - lim || (ccc < lim && bzd.top() > 0))){
            q.push(bzd.top());
            ccc++;
            s += bzd.top();
            bzd.pop();
        }
    }
    for(i = lim + 1; i >= 1; i--){
        const int1 x = pi[i];
        s += a[x][3];
        ppp -= a[x][1];
        q.push(a[x][2] - a[x][3]);
        ccc++;
        s += a[x][2] - a[x][3];
        while(ccc > lim || (ccc > 0 && ccc > n - i + 1 - lim && q.top() < 0)){
            bzd.push(q.top());
            s -= q.top();
            ccc--;
            q.pop();
        }
        while(!bzd.empty() && (ccc < n - i + 1 - lim || (ccc < lim && bzd.top() > 0))){
            q.push(bzd.top());
            ccc++;
            s += bzd.top();
            bzd.pop();
        }
        ans = max(ans,s + ppp);
    }
    return pe(ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int1 T = read(); T; T--){
        solve();
    }
    return 0;
}
/*
有点想写【数据删除】CCF，但是想了想不值得，算了
但是我真的要退役了啊……
luogu510555，21 年那个自爆uid的也是我
四年过去了，还是菜得扣脚
今年分数还没去年高，窒息了，我还是搞文化吧……
*/