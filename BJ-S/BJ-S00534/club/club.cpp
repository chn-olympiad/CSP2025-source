#include<bits/stdc++.h>
using namespace std;
int a[4][100005],aa[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0,maxi=0,maxx=0,a123,cnt[4]={0,0,0,0},k;
        bool f1=0,f2=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[2][i]!=0)f1=1;
            if(a[3][i]!=0)f2=1;
        }
        if(f1==0&&f2==0)
        {
            for(int i=1;i<=n;i++)aa[i]=a[1][i];
            sort(aa+1,aa+n+1);
            for(int i=n;i>n/2;i--)ans+=aa[i];
            cout<<ans<<endl;

        }
        
        else{

            for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++)
            {
                if(a[1][j]>maxx)
                {
                    maxx=a[1][j];
                    maxi=j;
                    a123=1;
                }
                if(a[2][j]>maxx)
                {
                    maxx=a[2][j];
                    maxi=j;
                    a123=2;
                }
                if(a[3][j]>maxx)
                {
                    maxx=a[3][j];
                    maxi=j;
                    a123=3;
                }

            }
            if(cnt[a123]==n/2)a[a123][maxi]=0;
            else
            {
                ans+=maxx;
                a[1][maxi]=0;
                a[2][maxi]=0;
                a[3][maxi]=0;
                cnt[a123]++;
            }
            maxx=0;


        }
        cout<<ans<<endl;
        }

    }
    return 0;
}
