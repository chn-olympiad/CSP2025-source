#include<bits/stdc++.h>
using namespace std;
const int mx=5010;
int a[mx],n,i,j,x=0,c,r,ans=0,mi=0;
int s=0,cnt=0;
bool b;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
    {
        s+=a[i];
        cnt++;
        for(j=i+1;j<=n;j++)
        {
            s+=a[j];
            cnt++;
            mi=max(a[i],a[j]);
            //mi=max(mi,a[j]);
            //if(s>2*mi) ans++;
            for(c=1;c<=n;c++)
            {
                s+=a[j+c];
                mi=max(mi,a[j+c]);
                cnt++;
                while(cnt>=3&&s>2*mi){
                    ans++;
                    cnt=0;
                    s-=a[j+c];
                    b==1;
                }
            }

        }
    }
    cout<<ans;
}
