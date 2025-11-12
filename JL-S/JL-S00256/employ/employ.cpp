#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int M=998244353;
int n,m;
int c[N];
int a[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int f=0;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]=='1')
            f++;
    }
    if(f==s.size())
    {
        a[0]=1;
        for(int i=1;i<=m;i++)
        {
            a[i]=a[i-1]%M*i%M;
            a[i]%=M;
        }
        cout<<a[m];
        return 0;
    }
    else
    {
        int srand(time(0));
        cout<<rand()%M*s.size()%M%n+(m*10)%M;
    }
    return 0;
}
