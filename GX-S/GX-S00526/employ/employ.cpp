#include<bits/stdc++.h>
using namespace std;
char s[510];
int a[510];
int flag[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d%s",&n,&m,s);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        flag[a[i]]++;
    }
    int ret=1;
    for(int i=1; i<=500; i++)
    {
        if(flag[i]!=0)
        {
            ret*=flag[i];
            ret%=998244353;
        }
    }
    printf("%d",ret);
    return 0;
}
