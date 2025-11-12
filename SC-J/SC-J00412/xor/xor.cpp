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
        freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
const int N=5e5+11,M=(1<<20)+5;
int n,k;
int a[N],ct[M];
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]^=a[i-1];
    }
    ct[0]=1;
    int rs=0;
    int p=0;
    for(int i=1;i<=n;i++) {
        if(ct[a[i]^k]) {
            rs++;
            while(p<i) {
                ct[a[p]]--;
                p++;
            }
        }
        ct[a[i]]++;
    }
    cout<<rs<<'\n';
    return 0;
}