//xjz0918 CSP-S2025 RP++
//FROM GAN NAN SHI DA FU ZHONG
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][10];
long long sum=0;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        if(n==2)
        {
            int max1=a[1][1],m1=1,m2=max(a[1][2],a[1][3]);
            if(a[1][2]>max1)
            {
                max1=a[1][2];m1=2;m2=max(a[1][1],a[1][3]);
            }
            if(a[1][3]>max1)
            {
                max1=a[1][3];m1=3;m2=max(a[1][1],a[1][2]);
            }
            int max2=a[2][1],mi2=1,mi1=max(a[2][2],a[2][3]);
            if(a[2][2]>max2)
            {
                max2=a[2][2];mi2=2;mi1=max(a[2][1],a[2][3]);
            }
            if(a[3][1]>max2){
                    max2=a[2][3];mi2=3;mi1=max(a[2][1],a[2][2]);
            }
            if(m1!=mi2)
            {
                cout<<max1+max2<<endl;
                continue;
            }
            else{
                if(max1>max2)
                {
                    cout<<max1+mi1<<endl;
                }
                else{
                    cout<<max2+m2<<endl;
                }
            }

        }
        else{
            for(int i=1;i<=n;i++)
            {
                if(a[i][1]>a[i][3]&&a[i][2]>a[i][3])sum=sum+max(a[i][1],a[i][2]);
                else if(a[i][1]>a[i][2]&&a[i][3]>a[i][2])sum=sum+max(a[i][1],a[i][3]);
                else{
                    sum=sum+max(a[i][2],a[i][3]);
                }
            }
            cout<<sum<<endl;
        }

    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],a2[100010],a3[100010],m[100010][10]={-1},dp[100010];
//bool ;
long long sum=0,maxsum=0,c1=0,c2=0,c3=0;
int dfs(int t)
{
    if(t>=n)
    {
        return sum;
    }
    for(int i=1;i<=3;i++)
    {
        if(b1[i]==false)
        {
            b1[i]=true;
            sum+=a1[i];
            dfs(t+1);
            b1[i]=false;
            //sum-=a1[i+1];
        }
        if(b2[i]==false)
        {
            b2[i]=true;
            sum+=a2[i];
            dfs(t+1);
            b2[i]=false;
            //sum-=a1[i+1];
        }
        if(b3[i]==false)
        {
            b3[i]=true;
            sum+=a3[i];
            dfs(t+1);
            b3[i]=false;
            //sum-=a3[i+1];
        }
    }
}
int dtgh(int v[],int n)
{
    for(int i=n/2;i<=1;i--)
    {
        dp[i]=max(dp[i],dp[i-1]+v[i]);
    }
    return dp[n];
}
int main()
{
    //freopen("club1.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
            c1+=a1[i];
            c2+=a2[i];
            c3+=a3[i];
        }
        if(c1==max(c1,c2,c3))
        {
            cout<<dtgh(a1,n);
        }
        else if(c2==max(c1,c2,c3))
        {
            cout<<dtgh(a2,n);
        }
        //cout<<dfs(1)<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int z=1;z<=n;z++)
                {

                }
            }
        }
    }
    return 0;
}*/
