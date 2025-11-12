#include <iostream>
#include <cstdio>
using namespace std;

int t,n,a[100001][4],m[100001],cnt[4],sum;
bool succ;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        sum=0;
        for(int j=1;j<=n;j++)
        {
            m[j]=-1; 
            for(int k=1;k<=3;k++)
            {
                cin>>a[j][k];
                if(a[j][k]>a[j][m[j]] || m[j]==-1) 
                    m[j]=k;
            }
            cnt[m[j]]++;
            sum+=a[j][m[j]];  
        }
        succ=true;
        for(int j=1;j<=3;j++)
        {
            if(cnt[m[j]]>(n/2))
                succ=false;
        }
        if(succ)
        {
            cout<<sum<<endl;
            continue;
        }
    }
    return 0;
}