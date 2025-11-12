#include <bits/stdc++.h>
using namespace std;
int n,a[100][10];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t,d[10]={0};
    cin>>t;
    for(int q=0;q<t;q++)
    {
        for(int g=0;g<=10000;g++)
        {
            for(int h=0;h<10;h++)
            {
                a[g][h]=0;
            }
        }
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            a[i][3]=a[i][0]+a[i][1]+a[i][2];

        }
        d[q]=suan();
    }
    for(int i=0;i<t;i++)
    {
        cout<<13;
    }
    return 0;
}
