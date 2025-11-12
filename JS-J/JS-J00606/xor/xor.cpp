#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int a[500001];
int b[500001];
void query(int l,int r)
{
    if(l>r)    return;
    if(l==r)
    {
        if(a[l]==k)
        {
            p++;
            b[p]=l;
        }
        return;
    }
    int mid=(l+r)/2;
    if(a[mid]==k)
    {
        p++;
        b[p]=l;
    }
    query(l,mid-1);
    query(mid+1,r);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)    cin>>a[i];
    int cnt=0,cur=0;
    if(k==0)
    {
        for(int i=1;i<=n;i++)    if(a[i]==a[i-1]||a[i]==0)    a[i]=-1,a[i-1]=-1,cnt++;
        cout<<cnt;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)    cnt++,cur=0;
        else
        {
            cur^=a[i];
            if(cur==k)    cnt++,cur=0;
        }
    }
    /*
    query(1,n);
    sort(b+1,b+p+1);
    b[++p]=n;
    b[0]=1;
    for(int i=0;i<p;i++)
    {
        cur=0;
        for(int j=b[i]+1;j<b[i+1];j++)
        {
            cur^=a[j];
            if(cur==k)    cnt++,cur=0;
        }
    }*/
    cout<<cnt/*+p*/;
    return 0;
}
