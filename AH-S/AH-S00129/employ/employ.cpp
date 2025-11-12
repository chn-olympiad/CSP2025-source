#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    long long s=1;
    int p=0,q=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        s*=i;
        s%=998244353;
        if(k<=q)
        {
            q++;
            continue;
        }
        p++;
        if(p==m)
        {
            break;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
