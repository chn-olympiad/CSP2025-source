#include<iostream>
using namespace std;
int qujians=0,qujian[500010][2],n;
bool check(int l,int r)
{
    for(int i=0;i<qujians;i++)
    {
        int l2=qujian[i][0];
        int r2=qujian[i][1];
        for(int k=l2;k<=n;k++)
        {
            if(l<=k&&k<=r&&l2<=k&&k<=r2)return false;
        }
    }
    return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k,as[500010],temp=0,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>as[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int temp=as[i];
            for(int k=i+1;k<=j;k++)
            {
                temp^=as[k];
            }
            if(temp==k)
            {
                if(check(i,j))
                {
                    ans++;
                    qujian[qujians][0]=i;
                    qujian[qujians][1]=j;
                    qujians++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
