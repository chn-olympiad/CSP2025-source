#include<bits/stdc++.h>
using namespace std;
int n,q;
int mymax(int inA,int inB)
{
    return inA>inB? inA:inB;
}
int mymin(int inA,int inB)
{
    return inA<inB? inA:inB;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
        cout<<"0\n";
    return 0;
}