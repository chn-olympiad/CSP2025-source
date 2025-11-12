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
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
const int N=15;
int n,m;
int a[N*N],b[N*N];
bool cmp(int x,int y) { return a[x]>a[y]; }
int main() {
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        cin>>a[i];
        b[i]=i;
    }
    std::sort(b+1,b+(n*m)+1,cmp);
    for(int i=1,x=1,y=1;i<=n*m;i++) {
        if(b[i]==1) {
            cout<<x<<' '<<y<<'\n';
            break;
        }
        if(x&1) {
            if(y==n) x++;
            else y++;
        }
        else {
            if(y==1) x++;
            else y--;
        }
    }
    return 0;
}