#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    /*
    int a,b;
    cin>>a>>b;
    int s=a^b;//xor
    cout<<s;
    */

    int n,k,a[500005];
    cin>>n>>k;
    int nums=0;
    int nums2=0;
    int nums3=0;
    int nums4=0;
    int del=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            nums++;
        }
        if(a[i]==0)
        {
            nums2++;
        }
        if(a[i]>1)
        {
            nums3++;
        }
        if(i>=2)
        {
            if(a[i-1]==1&&a[i]==1&&i-1!=del)
            {
                nums4++;
                del=i;
            }
        }
    }
    if(k==0&&nums==n)
    {
        cout<<n/2;
    }
    else if(k==1&&nums2!=0&&nums3==0)
    {
        cout<<n-nums2;
    }
    else if(k==0&&nums2!=0&&nums3==0)
    {
        cout<<nums2+nums4;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
