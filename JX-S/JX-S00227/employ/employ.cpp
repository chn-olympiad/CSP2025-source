#include<bits/stdc++.h>;
using namespace std;
long long n,m,a[555],cnt,sum=1;
long long f(long long n)
{
    long long sum=1;
    for(int i=1;i<=n;i++)
    {
        sum*=i;
    }
    return sum;
}
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(s[i]=='1') cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        long long mu=f(cnt-m)*f(m);
        sum*=f(cnt)/mu;
    }
    cout<<sum;
    return 0;
}
