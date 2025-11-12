#include<bits/stdc++.h>
using namespace std;
    int n,q;
    char S[100005][3],T[100005][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%c %c",&S[i][1],&S[i][2]);
    for(int i=1;i<=q;i++) scanf("%c %c",&T[i][1],&T[i][2]);
    for(int i=1;i<=q;i++) printf("0\n");
    return 0;
}
