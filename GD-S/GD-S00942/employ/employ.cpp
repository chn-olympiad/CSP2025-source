#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>

#define LL long long
#define pLL pair<LL,LL>

using namespace std;

void FileIO(string File) {
    freopen((File+".in").c_str(),"r",stdin);
    freopen((File+".out").c_str(),"w",stdout);
}
LL read() {
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

const LL N=505;
const LL M=505;

LL n,m;
LL a[N];
LL ans;
LL p[N];
bool anyin[N][N];
string s;

int main() {
    FileIO("employ");
    n=read(),m=read();
    cin>>s;
    for(int i=1;i<=n;i++) {
        anyin[i][i]=(s[i-1]=='1');
        for(int j=i+1;j<=n;j++) {
            anyin[i][j]=anyin[i][j-1]|(s[j-1]=='1');
        }
    }
    for(int i=1;i<=n;i++) {
        a[i]=read();
        p[i]=i;
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         printf("%lld ",anyin[i][j]);
    //     }
    //     puts("");
    // }
    do {
        LL sum=0;
        for(int i=1;i<=n;i++) {
            if(s[i]=='0') continue;
            if(i<=a[p[i]]||anyin[i-a[p[i]]][i-1]) {
                sum++;
            }
        }
        if(sum>=m) ans++;
    } while(next_permutation(p+1,p+1+n));
    printf("%lld",ans);
    return 0;
}
/*
3 2
101 
1 1 2
*/