#include<bits/stdc++.h>
using namespace std;
long long qw[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a=0;
    string z;
    cin>>z;
    for(int i=0;i<z.size();i++)
    {
        if(z[i]>='0'&&z[i]<='9')
        {
            a++;
            qw[a]=z[i]-'0';
        }
    }
    sort(qw+1,qw+1+a,greater<long long>());
    for(int i=1;i<=a;i++)
    {
        cout<<qw[i];
    }
    return 0;
}
