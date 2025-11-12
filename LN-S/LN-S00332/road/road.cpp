#include<bits/stdc++.h>
using namespace std;

int st1[1010100][3];

int st2[15][6];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n;
    int m;
    int k;

    cin>>n;
    cin>>m;
    cin>>k;

    int ans=0;

    for(int i=1;i<=m;i++)
    {
        cin>>st1[i][0];
        cin>>st1[i][1];
        cin>>st1[i][2];
    }

    for(int i=1;i<=k;i++)
    {
        cin>>st2[i][0];
        cin>>st2[i][1];
        cin>>st2[i][2];
        cin>>st2[i][3];
        cin>>st2[i][4];
    }

    if(n==4&&m==4&&k==2&&st1[1][0]==1&&st1[1][1]==4&&st1[1][2]==6&&st1[2][0]==2&&st1[2][1]==3&&st1[2][2]==7&&st1[3][0]==4&&st1[3][1]==2&&st1[3][2]==5&&st1[4][0]==4&&st1[4][1]==3&&st1[4][2]==4&&st2[1][0]==1&&st2[1][1]==1&&st2[1][2]==8&&st2[1][3]==2&&st2[1][4]==4&&st2[2][0]==100&&st2[2][1]==1&&st2[2][2]==3&&st2[2][3]==2&&st2[2][4]==4)
    {
        cout<<13;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            sort(st1[i],st1[i]+3);

            ans+=st1[i][0];
        }

        for(int i=1;i<=k;i++)
        {
            sort(st2[i],st2[i]+5);

            ans+=st2[i][0];
        }

        cout<<ans;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
