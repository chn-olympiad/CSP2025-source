#include <bits/stdc++.h>
#define pb push_back
using namespace std;
// struct node
// {
//     int s,e;
// }book[10000005];
int n,m;
long long k,a[500005],sum[500005],ans;
// bool cmp(node x,node y)
// {
//     if(x.s!=y.s)
//         return x.s<y.s;
//     return (x.e-x.s)<(y.e-y.s);
// }
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i=i+2)
        sum+=n-i+1;
    cout<<sum;
    // cin>>n>>k>>a[1];
    // sum[1]=a[1];
    // for(int i=2;i<=n;i++)
    // {
    //     cin>>a[i];
    //     sum[i]=sum[i-1]^a[i];
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     if(sum[i]==k)
    //         m++,book[m].s=1,book[m].e=i;
    //     for(int j=1;j<i;j++)
    //         if((sum[i]^sum[j])==k)
    //             m++,book[m].s=j+1,book[m].e=i;
    // }
    // book[0].s=book[0].e=0;
    // sort(book+1,book+1+m,cmp);
    // for(int i=1;i<=m;i++)
    // {
    //      if(book[i].s<=book[i-1].e)
    //          continue;
    //     ans++;
    //     cout<<book[i].s<<" "<<book[i].e<<endl;
    // }
    // cout<<ans;
    return 0;
}
/*
1 2
1 3
3 4
4 4
*/

/*
1 3 - 3
2 5 - 4
3 7 - 5
3 4 - 2
7 8 - 2
5 7 - 3
2 4 - 3
1 2 - 2
6 7 - 2
*/
