#include <bits/stdc++.h>
using namespace std;
int s[1010][3],t[1010][3];
int main () {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&s[i][1],&s[i][2]);
    }
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&t[i][1],&t[i][2]);
    }
}