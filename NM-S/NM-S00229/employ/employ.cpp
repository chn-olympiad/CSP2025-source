#include <bits/stdc++.h>
using namespace std;
int n,m,x;
char s[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i++)
        if(s[i] == '1')
            x++;
    if(x < m){
        printf("0");
        return 0;
    }
}
