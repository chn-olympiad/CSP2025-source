#include<iostream>
using namespace std;
long t,n,k=0,chancesum=0;//t-stick total, n-the number of chance
bool b[5010];
int stick[5010];
bool g()
{
    int max=-1,sum=0;
    for(int i=1;i<=t;i++)
    {
        if(b[i])
        {
            //cout<<stick[i]<<' ';
            sum+=stick[i];
            if(stick[i]>max)
            {
                max=stick[i];
            }
        }
    }
    //cout<<sum<<' '<<max<<endl;
    if(sum>max*2)
    {
        return true;
    }
    return false;
}
void f(int a)
{
    k++;
    for(int i=a;i<=t;i++)
    {
        b[i]=true;
        if(k==n&&g())
        {
            chancesum++;
            chancesum=chancesum%998244353;
        }
        if(t-i>=n-k&&k<n)
        {
            f(i+1);
        }
        b[i]=false;
    }
    k--;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>stick[i];
    }
    for(int i=3;i<=t;i++)
    {
        n=i;
        f(1);
    }
    cout<<chancesum;
    return 0;
}
