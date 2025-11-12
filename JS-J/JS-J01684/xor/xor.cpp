#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k,ans;
int a[500007];


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool flag=true;
    if(n<=1000) flag=false;
    if(k>1)flag=false;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        if(k==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                    ans++;
                if(a[i]==1&&a[i+1]==1)
                {
                    ans++;
                    i+=1;
                }
            }
            printf("%d",ans);
        }
        else
        {
            for(int i=1;i<=n;i++)
                if(a[i]==1)
                    ans++;
            printf("%d",ans);
        }
        return 0;
    }
    int last=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=i;j<=n;j++)
        {
            sum=sum^a[j];
            if(sum==k)
            {
                //cout<<i<<" "<<j<<" "<<ans<<" "<<last<<"\n";
                if(i>last)
                {
                    ans++;
                    last=j;
                }
                else if(j<last)
                {
                    last=j;
                }
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
