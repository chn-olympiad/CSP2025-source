#include<bits/stdc++.h>
using namespace std;
int m,n,a[505],bj[505],b[505],op2;
long long sum,op[505];
string s;
void f(int c)
{
    if(c==n+1)
    {
        int g=0,k=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]>g&&s[i-1]=='1') k++;
            else g++;
            if(k>=m)
            {
                sum++;
                sum%=998244353;
                return;
            }
            if(g>n-m) return;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(bj[i]==0)
        {
            bj[i]++;
            b[i]=a[c];
            f(c+1);
            bj[i]--;
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        //if(a[i]==0) op2++;
    }
    if(s.find('0')-1>n)
    {
        op[1]=1;
        for(int i=2;i<=n;i++)
        {

        }
        printf("%lld",(op[m]%998244353)*(op[n-m]%998244353)%998244353);
        return 0;
    }
    f(1);
    printf("%lld",sum%998244353);
    return 0;
}
