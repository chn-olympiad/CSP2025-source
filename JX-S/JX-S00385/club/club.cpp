#include<bits/stdc++.h>
using namespace std;
long long t,n,s1[100005],s2[100005],s3[100005],sum;
struct node
{
    int a1,a2,a3;
    bool flag=0;
}f[100005];
bool cmp1(node x,node y)
{
    return x.a1>y.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>f[i].a1>>f[i].a2>>f[i].a3;
        }
        sort(f+1,f+1+n,cmp1);
        for(int i=1;i<=n/2;i++)
        {
            sum+=f[i].a1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
