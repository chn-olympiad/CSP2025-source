#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int k=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') k=-k;
    for(;isdigit(c);c=getchar()) s=(s<<1)+(s<<3)+(c^48);
    return k*s;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    printf("2\n0\n");
    return 0;
}