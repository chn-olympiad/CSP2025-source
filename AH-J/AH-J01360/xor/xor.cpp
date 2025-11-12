#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],arr[21];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    for(int i=1;i<=20;i++)arr[i]=1<<i;
    scanf("%d%d",&n,&k);
    bool flag1=true,flag2=true;
    int m=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m=max(m,a[i]);
        if(a[i]!=1)flag1=false;
        if(a[i]>1)flag2=false;
    }
    int x=0,y=0;
    for(int i=1;i<=20;i++)
    {
        if(arr[i]<=m)x=i+1;
        else break;
    }
    for(int i=1;i<=20;i++)
    {
        if(arr[i]<=k)y=i+1;
        else break;
    }
    if(y>x)printf("0");
    else
    {
        if(flag1==true)
        {
            if(k==0)printf("%d",n/2);
            if(k==1)printf("%d",n);
        }
        else
        {
            if(flag2==true)
            {
                int ans=0;
                if(k==0)
                {
                    for(int i=1;i<=n;i++)
                    {
                        if(a[i]==0)ans++;
                        else if(i<n&&a[i]==1&&a[i+1]==1)ans++,i++;
                    }
                }
                if(k==1)
                {
                    for(int i=1;i<=n;i++)
                        if(a[i]==1)ans++;
                }
                printf("%d",ans);
            }
        }
    }
    return 0;
}
