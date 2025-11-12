#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using ll=long long;
const int N=1e5+11;
int n;
int a[N][3],mx[N],se[N],c[3];
int b[N];
void clr() { for(int i=0;i<3;i++) c[i]=0; }
bool cmp(int x,int y) { return a[x][mx[x]]-a[x][se[x]]<a[y][mx[y]]-a[y][se[y]]; }
void slv() {
    cin>>n;
    ll rs=0;
    for(int i=1;i<=n;i++) {
        mx[i]=se[i]=-1;
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
            if(mx[i]==-1||a[i][j]>a[i][mx[i]])
                se[i]=mx[i],mx[i]=j;
            else if(se[i]==-1||a[i][j]>a[i][se[i]])
                se[i]=j;
        }
        rs+=a[i][mx[i]];
        c[mx[i]]++;
        // db("%d: %d %d\n",i,mx[i],se[i]);
    }
    for(int i=0;i<3;i++) {
        if(c[i]>(n>>1)) {
            int k=0;
            for(int j=1;j<=n;j++)
                if(mx[j]==i) b[++k]=j;
            std::sort(b+1,b+k+1,cmp);
            for(int j=1;j<=c[i]-(n>>1);j++) {
                int x=b[j];
                rs-=(a[x][mx[x]]-a[x][se[x]]);
            }
            break;
        }
    }
    cout<<rs<<'\n';
}
int main() {
    int T; cin>>T;
    while(T--) slv(),clr();
    return 0;
}