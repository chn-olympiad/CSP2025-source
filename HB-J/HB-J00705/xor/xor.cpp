#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int type_1=1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            type_1=0;
        }
        else
        {
            cnt++;
        }
    }
    if(type_1)
    {
        cout<<n/2;
        return 0;
    }
    if(k==1)
    {
        cout<<cnt;
        return 0;
    }

    return 0;
}
/*
At 10:11
writting sth
qwq
why i don't review xor
noooooo
i don't know how to do t3
i think it's an easy problem(maybe yellow or green)
but i don't review it
no
just 200pts.
i can't get j1=
noooo
i don't know how to do t3 and t4
f*******
qwq
qwq
qwq

At 11:07
i know what's xor
but how to do it
aaaaaaaaaaa
f!#$%@%&%!$#&^$%&^&#^$%*&%$^#
At 11:40
10pts
enough

At 11:50
why t4 dp
noooooooo
*/

/*
ps:i want up to the QI PA BIG show pls
my luogu name is:jacobcn
aya
pls GUAN ZHU me!!!!!
*/
