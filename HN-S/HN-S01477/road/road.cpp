#include<bits/stdc++.h>
#define N 100000
#define M 2000000
#define K 0
#define INF 1000000000000000
#define mod 0
#define int1 long long
using namespace std;
int1 n,m,k,i,j,ans;
struct qwq{
    int1 x,y,z;
} e[M + 5];
int1 f[N + 5];
int1 bs;
int1 c[N + 5];
int1 del[N + 5];
bool cmp(qwq x,qwq y){
    return x.z < y.z;
}
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
int1 find(const int1 x){
    if(x == f[x]){
        return x;
    }
    return f[x] = find(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(),m = read(),k = read();
    for(i = 1; i <= m; i++){
        const int1 x = read(),y = read(),z = read();
        e[++bs] = (qwq){x,y,z};
    }
    // e[++bs] = (qwq){n + 1,1,0};
    for(i = 1; i <= k; i++){
        const int1 now = n + i + 1;
        c[i] = read();
        for(j = 1; j <= n; j++){
            e[++bs] = (qwq){now,j,read()};
        }
        del[i] = 2;
    }
    for(i = n + k + 1; i >= 1; i--){
        f[i] = i;
    }
    sort(e + 1,e + bs + 1,cmp);
    for(i = 1; i <= bs; i++){
        const int1 fx = find(e[i].x),fy = find(e[i].y);
        if(fx != fy){
            f[fy] = fx;
            // if(e[i].x <= n + 1 || e[i].x > n + 1 && !(--del[e[i].x - n - 1])){
                ans += e[i].z;
            // }
        }
    }
    for(i = 1; i <= k; i++){
        if(!del[i]){
            ans += c[i];
        }
    }
    pe(ans);
    return 0;
}
/*
只会打特殊性质，和一位
绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望绝望
*/