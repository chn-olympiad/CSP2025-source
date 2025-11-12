#include<bits/stdc++.h>
using namespace std;

struct xx
{
    int l,r;
}x[500001];
int a[500005];
bool cmp(xx a,xx b)
{
    if(a.r-a.l==b.r-b.l)return a.l<b.l;
    return a.r-a.l<b.r-b.l;
}
bool bg[500001]={1,0};
int main()//^:xor
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,p=0,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j=1;j<=i;j++)
        {
            a[i]=(a[i]^t);
            if(a[i]==k)
            {
                x[p].l=j,x[p].r=i,p++;
                a[i]=2147483647;
                break;
            }
        }
    }
    sort(x+1,x+p-1,cmp);
    for(int i=1;i<=p;i++)
    {
        bool flag=0;
        for(int j=x[i].l-1;j<=x[i].r;j++)flag=flag||bg[j];
        if(flag==0)
        {
            sum++;
            //cout<<x[i].l-1<<" "<<x[i].r<<endl;
            for(int j=x[i].l-1;j<=x[i].r;j++)bg[j]=1;
        }
    }
    cout<<sum;
    return 0;
}
