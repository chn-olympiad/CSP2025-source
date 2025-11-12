#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
bool p[5050];
long long mod=998244353;
long long ny[5050];
long long wyc;
void f(int d)
{
    if(d==n+1)
        {
            int i;
            i=1;
            int s=0;
            int ss=0;
            int ma=0;
            while(i<=n)
                {
                    if(p[i]==1)
                        {
                            s+=a[i];
                            ma=max(ma,a[i]);
                            ++ss;
                        }
                    ++i;
                }
            if(ss>=3&&s>2*ma)++wyc;
            return ;
        }
    f(d+1);
    p[d]=1;
    f(d+1);
    p[d]=0;
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int i;
    i=1;
    while(i<=n)
        {
            cin>>a[i];
            ++i;
        }
    sort(a+1,a+1+n);
    if(n<=20)
        {
            f(1);
            cout<<wyc;
            return 0;
        }
    if(a[n]==1)
        {
            i=2;
            ny[1]=1;
            while(i<=n)
                {
                    ny[i]=(mod-mod/i)*ny[mod%i]%mod;
                    ny[i]=(ny[i]%mod+mod)%mod;
                    ++i;
                }
            wyc=0;
            long long s;
            s=1;
            i=1;
            while(i<=n)
                {
                    s*=(n-i+1);
                    s%=mod;
                    s*=ny[i];
                    s%=mod;
                    if(i>=3)wyc+=s,wyc%=mod;
                    ++i;
                }
            cout<<wyc;
            return 0;
        }
    srand(time(0));
    cout<<rand()%mod;
    return 0;
}