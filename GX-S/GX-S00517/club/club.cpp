#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t>0)
    {
        int n,i,j,as=0;
        cin>>n;
        if(n==2)
        {
            for(i=0;i<n;i++)
            {
                int a[3];
                for(j=0;j<3;j++)
                {
                    cin>>a[j];
                }
                sort(a,a+3);
                as=as+a[2];
            }
            cout<<as;
            t--;
            if(t!=0) cout<<endl;
            continue;
        }
    }
    return 0;
}
