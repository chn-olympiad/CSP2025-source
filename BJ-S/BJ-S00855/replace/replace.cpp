#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=3e6;
LL n;
ll q;
int main(){
    freopen("replace.in",r,cin);
    freopen("replace.out",w,cout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    char s[MAXN];
    char q[MAXN];
    int c[n][MAXN];
    int c_q[q][MAXN];
    for(LL i=1;i<=n;i++){
        char s1[MAXN];
        char Ss2[MAXN];
        cin>>s1>>s2;
        int len=length(s1);
        for(int j=0;j<len;j++){
            c[i][j]=s1[j]-s2[j];
        }
    }
    for(LL i=1;i<=q;i++){
        char q1
    }
}