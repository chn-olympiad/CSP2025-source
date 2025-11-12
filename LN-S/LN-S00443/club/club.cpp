#include<bits/stdc++.h>
using namespace std;
struct student
{
    int p;
    int q;
};
bool cmp(student m1,student m2)
{
    return m1.p>m2.p;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,ans=0;
        int a[100001][3];
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        if(n==2)
        {
            student k[3],f[3];
            for(int i=0;i<3;i++)
            {

                k[i].p=a[0][i];
                k[i].q=i;}
            for(int i=0;i<3;i++){
                f[i].p=a[1][i];
                f[i].q=i;}
            sort(f,f+3,cmp);
            sort(k,k+3,cmp);
            if(k[0].q!=f[0].q)  cout<<k[0].p+f[0].p<<endl;
            else    if(k[0].p-k[1].p>f[0].p-f[1].p) cout<<k[0].p+f[1].p<<endl;
            else    cout<<k[1].p+f[0].p<<endl;
            continue;
        }
        student b[100001];
        for(int i=0;i<n;i++)
        {
            b[i].p=a[i][0]-a[i][1];
            b[i].q=i;
        }
        sort(b,b+n,cmp);
        for(int i=0;i<n/2;i++)
        {
            ans+=a[b[i].q][0];
        }
        for(int i=n/2;i<n;i++)
        {
            ans+=a[b[i].q][1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
