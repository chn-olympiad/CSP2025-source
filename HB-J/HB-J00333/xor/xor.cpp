#include <iostream>
#include <cstring>
using namespace std;
const int N=3000001,M=600000;
int a[M],p[N],n,lst=0,num,k,ans=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        num=a[i]^num;
        if(p[num^k])
        {
            //cout<<i<<endl;
            int cnt=0;
            ans++;
            for(int j=lst+1;j<=i;j++)
            {
                cnt=cnt^a[j];
                p[cnt]=0;
            }
            p[0]=1;
            lst=i;
            num=0;
        }
        else p[num]=1;
        //cout<<num<<endl;
    }
    cout<<ans;
    return 0;
}