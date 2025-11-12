#include<bits/stdc++.h>
using namespace std;
int arr[500005];
vector<int> sh_er(int n)
{
    vector<int>brr;
    for(;n;n/=2)
        brr.push_back(n%2);
    return brr;
}
int er_sh(vector<int>brr)
{
    int n=0;
    for(int i=0;i<brr.size();i++)
    {
        int n1=brr[i];
        for(int j=1;j<=i;j++)
            n1*=2;
        n+=n1;
    }
    return n;
}
int yihuo(int a,int b)
{
    vector<int>a1=sh_er(a);
    vector<int>b1=sh_er(b);
    int lena=a1.size(),lenb=b1.size();
    if(lena>lenb)
        for(int i=1;i<=lena-lenb;i++)
            b1.push_back(0);
    else if(lenb>lena)
        for(int i=1;i<=lenb-lena;i++)
            a1.push_back(0);
    int len=max(lena,lenb);
    for(int i=0;i<len;i++)
    {
        if(a1[i]==1&&b1[i]==1)a1[i]=0;
        else if(a1[i]==0&&b1[i]==0)a1[i]=1;
        else a1[i]=1;
    }
    return er_sh(a1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        a=arr[i];
        if(a==k)
        {
            cnt++;
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            a=yihuo(a,arr[j]);
            if(a==k)
            {
                cnt++;
                i=j;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
