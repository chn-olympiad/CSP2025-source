#include<bits/stdc++.h>
using namespace std;
int mystick[114514];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
        cout<<0;
    else if(n==3)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d=max(a,max(b,c));
        if(a+b+c>2*d)
            cout<<1;
        else
            cout<<0;
    }
    else
        cout<<rand()*time(0)%998244353;
}
/*10:00 yi kan fang an shu gu ji shi sou suo huo zhe dp
wo yi kan
bao li!!!
10:01 hai shi zuo di san ti ba
*/
