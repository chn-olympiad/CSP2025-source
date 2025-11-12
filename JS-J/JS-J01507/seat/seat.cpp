#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    int n1=n*m;
    for(int i=1;i<=n1;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    int sum=0;
    for(int i=2;i=n1;i++)
    {
        if(a[i]>x)
            sum++;
    }
    sum+=1;
    int ans_m=sum/n;
    int y=sum-(ans_m*n);
    if(y==0) 
    {
        if(ans_m%2==0)
        {
            cout<<ans_m<<" 1";
        }
        else if(ans_m%2==1)
        {
            cout<<ans_m<<" "<<n;
        }
    }
    else if(y!=0)
    {
        ans_m++;
        cout<<ans_m<<" ";
        int ans_n=0;
        if(ans_m%2==0)
        {
            ans_n=n-y+1;
        }
        else if(ans_m%2==1)
        {
            ans_n=y;
        }
        cout<<ans_n;
    }

    return 0;
}