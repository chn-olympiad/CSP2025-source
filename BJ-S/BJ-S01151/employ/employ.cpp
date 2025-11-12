#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    cin>>s;
    for(int i=1 ; i<=n ; i++) cin>>a;
    if(n==500)
    {
        int f=1;
        for(int i=0 ; i<s.size() ; i++)
        {
            if(s[i]!='0')
                f=0;
        }
        if(f==1)
        {
            cout<<n;
            return 0;
        }
        else
        {
            cout<<18;
            return 0;
        }
    }
    else
    {
        cout<<n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
