#include<bits/stdc++.h>
#define N 200000
#define M 5000000
#define K 677
#define INF 0
#define mod 813697891
#define int1 long long
using namespace std;
int1 n,q,i;
char a[M + 5],b[M + 5];
int1 hsh1,hsh2;
unordered_map<int1,int1> cnt;
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
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n = read(),q = read();
    for(i = 1; i <= n; i++){
        const int1 lena = getst(a,1,2);
        getst(b,1,2);
        hsh1 = hsh2 = 0;
        for(int1 j = 1; j <= lena; j++){
            const int1 bzd = (a[j] - 'a' + 1) * 26 + b[j] - 'a';
            hsh1 = (hsh1 * K + bzd) % mod;
            hsh2 = hsh2 * K + bzd;
        }
        cnt[hsh1 * 1145141919 + hsh2]++;
    }
    while(q--){
        int1 ans = 0;
        const int1 lena = getst(a,1,2);
        getst(b,1,2);
        int1 l = 1,r = lena;
        while(a[l] == b[l] && l < lena){
            l++;
        }
        while(a[r] == b[r] && r > 1){
            r--;
        }
        for(i = 1; i <= l; i++){
            hsh1 = hsh2 = 0;
            for(int1 j = i; j <= lena; j++){
                const int1 bzd = (a[j] - 'a' + 1) * 26 + b[j] - 'a';
                hsh1 = (hsh1 * K + bzd) % mod;
                hsh2 = hsh2 * K + bzd;
                if(j >= r){
                    ans += cnt[hsh1 * 1145141919 + hsh2];
                    // if(cnt[hsh1 * 1145141919 + hsh2]){
                    //     ps(i),pe(j);
                    // }
                }
            }
        }
        pe(ans);
    }
    return 0;
}
/*
最后一舞居然都不一定有三位数吗，那你很有考试策略了
出考场应该就AFO了
*/