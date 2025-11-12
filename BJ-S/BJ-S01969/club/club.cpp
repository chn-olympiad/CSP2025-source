#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N][4];
bool b[N];
int sum;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])
                {   sum+=a[i][1];
                    b[i]=1;
                }
                else if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
                {   sum+=a[i][1];
                    b[i]=1;}
                else if(a[i][2]>a[i][3])
                {   sum+=a[i][2];
                    b[i]=0;}
                else if(a[i][3]>a[i][2])
                {
                    sum+=a[i][3];
                    b[i]=0;}

            }

        }
        cout<<sum<<"\n";
    }

    return 0;
}
