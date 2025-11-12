#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int flag[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool flag1=true;
    bool flag10=true;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)// A
            flag1=false;
        if(a[i]!=1&&a[i]!=0)// B
        {
            flag10=false;
        }
    }
    if(flag1==true)// A
    {
        cout<<n<<endl;
        return 0;
    }

    if(flag10==true)// B
    {
        if(k==0)
        {
            int ans2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                    ans2+=1;
                if(a[i]==1&&a[i+1]==1)
                {
                    ans2+=1;
                    i+=1;
                }
            }
            cout<<ans2<<endl;
        }
        else
        {
            int ans3=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                    ans3+=1;
            }
            cout<<ans3<<endl;
        }
        return 0;
    }

    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n-x+1;y++)
        {
            int www=y;
            while(www<=y+x-1)
            {
                if(flag[www]==1)
                    www+=1;
                else
                    break;
            }
            int sum=a[www];
            for(int z=www+1;z<=y+x-1;z++)
            {
                if(flag[z]==1)
                {
                    sum=-1;
                    break;
                }
                sum=sum^a[z];
            }
            if(sum==k)
            {
                ans+=1;
                for(int w=www;w<=y+x-1;w++)
                    flag[w]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
