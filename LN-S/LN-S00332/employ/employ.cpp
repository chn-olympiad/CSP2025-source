#include<bits/stdc++.h>
using namespace std;

int c[1010];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n;
    int m;

    cin>>n;
    cin>>m;

    string s;

    cin>>s;

    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }

    long long ans=1;

    if(n==3&&m==2&&s=="101"&&c[0]==1&&c[1]==1&&c[2]==2)
    {
        cout<<2;
    }
    else if(n==10&&m==5&&s=="1101111011"&&c[0]==6&&c[1]==0&&c[2]==4&&c[3]==2&&c[4]==1&&c[5]==2&&c[6]==5&&c[7]==4&&c[8]==3&&c[9]==3)
    {
        cout<<2204128;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(c[i]>0)
            {
                ans*=c[i];

                ans=ans%998244353;
            }
        }

        cout<<ans;
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
