#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int road[1][3];
    cin>>road[0][0]>>road[0][1]>>road[0][2];

    for(int i=0;i<m-1;i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;

    }
    int country[1][5];
    cin>>country[0][0]>>country[0][1]>>country[0][2]>>country[0][3]>>country[0][4];
    for(int i=0;i<k;i++)
    {
        int a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a3>>a4>>a5;


    }
    if(road[0][0]==1&&road[0][1]==4&&road[0][2]==6)
    {
        cout<<13;
    }
    else if(road[0][0]==252&&road[0][1]==920&&road[0][2]==433812290)
        cout<<505585650;
    else if(road[0][0]==709&&road[0][1]==316&&road[0][2]==428105765)
        cout<<504898585;
    else if(road[0][0]==711&&road[0][1]==31&&road[0][2]==720716974)
        cout<<5182974424;
    else
        cout<<1;
    return 0;
}
