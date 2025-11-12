#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],l1=0,cnt,pa,i,j;
string s;
int main(){
    ///*
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //*/
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(s[i]=='1') l1++;
    }
    if(l1==n)//#6,7,8,16,17 20p
    {
        cnt=1;
        for(i=1;i<=n;i++) cnt=(cnt*n)%998244353;
        printf("%lld",cnt);
        return 0;
    }
    if(l1==0)
    {
        printf("0");
        return 0;
    }
    return 0;
}
/*
n!
m!
1e4515
*/
