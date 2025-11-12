#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int thebest=2e5;
int n,k;
int a[N];
int sum[N];
int l[N],r[N],s[N],I=0;
int f[N];
int getsum(int tl,int tr)//bi qu jian
{
    return sum[tr]^sum[tl-1];
}
// void pts()
// {
//     long long _0=0,_1=0;
//     for(int i=1;i<=n;i++) 
//     {
//         if(a[i]==0) _0++;
//         if(a[i]==1) _1++; 
//     }
// }
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
    // if(n>=thebest) pts();
    // for(int i=1;i<=n;i++)
    //     for(int j=i;j<=n;j++)
    //     {
    //         if(i==j&&a[i]==k) 
    //             I++,l[I]=i,r[I]=j,s[I]=1,
    //             printf("[%d]:%d,%d\n",I,l[I],r[I]);
    //         else if(getsum(i,j)==k)
    //         {
    //             I++,l[I]=i,r[I]=j,s[I]=j-i+1;
    //             printf("[%d]:%d,%d\n",I,l[I],r[I]);
    //         } 
    //     }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
        {
            if(i>j) continue;
            if(i==j&&a[i]==k) 
                I++,l[I]=i,r[I]=j,s[I]=1;
                // printf("[%d]:%d,%d\n",I,l[I],r[I]);
            else if(getsum(i,j)==k)
            {
                I++,l[I]=i,r[I]=j,s[I]=j-i+1;
                // printf("[%d]:%d,%d\n",I,l[I],r[I]);
            } 
        }

    // for(int t=1;t<=I;t++)
    //     for(int j=s[t];j<=n;j++)
    //     {
    //         if(j!=r[t]) continue;
    //         if(j-s[t]>=0) f[j]=max(f[j],f[j-s[t]]+1);
    //     }
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        for(int t=1;t<=I;t++)
        {
            // if(i!=rt) continue;
            if(i==r[t]) f[i]=max(f[i],f[i-s[t]]+1);
            // if(i>=r[t]) break;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]); 
    // for(int i=1;i<=n;i++) printf("f[%d]:%d\n",i,f[i]);
    cout<<ans<<endl;
    // tryit();
    return 0;
}
/*
2 1 0 3
1 2 3 4
*/