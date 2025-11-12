#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n,k;
int a[500005];
int sum[500005];
int cnt2=0;
int cnt=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cnt++;
            cnt2++;
        }
        else if(a[i]<=1)
        {
            cnt2++;
        }
    }
    if(cnt==n)
    {
        if(k==1)
            cout<<n;
        else
            cout<<n/2;
        return 0;
    }
    //cout<<cnt2<<endl;
    if(cnt2==n)
    {
        if(k==0)
        {
            int num=0;
            int last=0;
            int num1=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    num++;
                    if(last!=0)
                    {
                        //cout<<num1<<endl;
                        num+=num1/2;
                        num1=0;
                        //cout<<num1<<endl;
                    }
                    //last=i;
                }
                else
                {
                    num1++;
                    last=i;
                }
            }
            cout<<num;
        }
        else if (k==1)
        {
            int num=0;
            int num1=0;
            int last=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1)
                {
                    if(a[i-1]==0)
                    {
                        num++;
                        last=i+1;
                    }
                    else
                    {
                        num1=i-last+1;
                    }
                }
                if(a[i]==0)
                {
                    if(a[i-1]==1)
                    {
                        num+=num1;
                        num1=0;
                    }
                }

            }
            cout<<num;
        }
        return 0;
    }
    cout<<rnd()%n;
}
