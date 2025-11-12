#include <bits/stdc++.h>
#define ll long long
#define MAXN 1001
using namespace std;
ll t,n[5],a[5][100001][3],agree[5][100001][3],num[5][3],ppl[5][100001],sum[5],z,x,c;
bool cotinu,ctnn[5][100001];
int main()
{
    //input
    //freopen("club1.in","r",stdin);
    //freopen("club.out","w",stdout);
    for(ll i=0;i<t;i++)
    {
        for(ll j=0;i<n[i];i++)
        {
            a[i][j][0]=-1;
            a[i][j][1]=-1;
            a[i][j][2]=-1;
            agree[i][j][0]=-1;
            agree[i][j][1]=-1;
            agree[i][j][2]=-1;
            ppl[i][j]=-1;
        }
    }
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        cin>>n[i];
        for(ll j=0;j<n[i];j++)
        {
            cin>>a[i][j][0];
            cin>>a[i][j][1];
            cin>>a[i][j][2];
        }
    }

    for(int i=0;i<t;i++)
    {
        if(a[i][0][0]>a[i][1][0]&&a[i][0][0]>a[i][1][1]&&a[i][0][0]>a[i][1][2])
        {
            sum[i]=sum[i]+a[i][0][0];
            sum[i]=sum[i]+max(a[i][1][1],a[i][1][2])
        }

        if(a[i][0][1]>a[i][1][0]&&a[i][0][1]>a[i][1][1]&&a[i][0][1]>a[i][1][2])
            sum[i]=sum[i]+a[i][0][1];
        if(a[i][0][2]>a[i][1][0]&&a[i][0][2]>a[i][1][1]&&a[i][0][2]>a[i][1][2])
            sum[i]=sum[i]+a[i][0][2];
        if(a[i][1][0]>a[i][0][0]&&a[i][1][0]>a[i][0][1]&&a[i][1][0]>a[i][0][2])
            sum[i]=sum[i]+a[i][1][0];
        if(a[i][1][1]>a[i][0][0]&&a[i][1][1]>a[i][0][1]&&a[i][1][1]>a[i][0][2])
            sum[i]=sum[i]+a[i][1][1];
        if(a[i][1][2]>a[i][0][0]&&a[i][1][2]>a[i][0][1]&&a[i][1][2]>a[i][0][2])
            sum[i]=sum[i]+a[i][1][2];
    }
    for(ll i=0;i<t;i++)
    {
        cout<<sum[i]<<endl;
    }
    return 0;
}
//^^^^|\^^^^^^/|^^^^
//^^^^|^\^^^^/^|^^^^
//^^^^///----\\\^^^^
//^^^////_/\_\\\\^^^
//^^^|||<O><O>|||^^^
//^^^|||   .  |||^^^
//^^^^VVV|  |VVV^^^^
//^^^/----------\^^^
//^^/^^^^^^^^^^^^\^^
//^^|############|^^
//10 9 8
// 4 0 0
// 5 4 3
// 4 0 2
//1 2 3
//1 2 3
//1 2 3
//1 3 2
//9 4 4 4
//10 4 4 2
//9 4 5 2
//8 4 5 0-
//9 0 5 4-
//9 0
//a[][][] ji lu hao gan du
//agree[][][] ji lu you xian ji
//sum[][][] ji lu da an
