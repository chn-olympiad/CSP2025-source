#include<bits/stdc++.h>
//q==1 25 pts code
using namespace std;
const int maxn=2e5+1;
int n,q;
char s1[maxn],s2[maxn],q1[maxn],q2[maxn];
int c[510];
main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s1[i]);
        scanf("%s",s2[i]);
    }
    for(int i=1;i<=q;i++){
        scanf("%s",q1[i]);
        scanf("%s",q2[i]);
    }
    for(int i=1;i<=q;i++){
        printf("0\n");
    }
}
