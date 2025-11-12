#include <bits/stdc++.h>
using namespace std;
int l1,l2,l3;
int max(int t,int j,int z)
{
    if(t>=j && t>=z)
    {
        l1++;
        return t;
    }else if(t<=j && j>=z){
        l2++;
        return j;
    }
    l3++;
    return z;
}
int mex(int t,int j,int z)
{
    if(t>=j && t<=z) return t;
    else if(t>=j && j>=z) return j;
    return z;
}
void px(int f[],int m)
{
    for(int i=1;i<=m;i++)
    {
        m=i;
        for(int j=i+1;j<m;j++)
        {
            if(f[j]<f[m]) m=j;
        }
        swap(f[m],f[i]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int q;
    cin>>q;
    for(int p=1;p<=q;p++)
    {
        int n,a[100005],b[100005],c[100005],d[100005];
        l1=l2=l3=0;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            d[i]=max(a[i],b[i],c[i]);
            ans+=d[i];
        }
        if(l1<=n/2 && l2<=n/2 && l3<=n/2)
        {
            cout<<ans<<endl;
            continue;
        }else{
            int s=max(l1,l2,l3)-n/2,leg=1;
            int e[100005];
            for(int j=1;j<=n;j++)
                e[j]=d[j]-mex(a[j],b[j],c[j]);
            px(e,n);
            cout<<s<<" ";
            while(s>0)
            {
                ans-=e[leg++];
                s--;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
